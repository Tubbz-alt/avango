import avango
import avango.script
import avango.gua
from avango.script import field_has_changed

import random
import src.provenance_utils as pu

class VTProjector(avango.script.Script):

  Material = avango.gua.SFMaterial()
  Transform = avango.gua.SFMatrix4()
  Graph = avango.gua.SFSceneGraph()
  Texture = avango.SFString()


  def __init__(self):
    self.super(VTProjector).__init__()
    loader = avango.gua.nodes.TriMeshLoader()

    self.group_node = avango.gua.nodes.TransformNode(Name = "projector_group")
    self.group_node.Transform.connect_from(self.Transform)

    self.geometry = loader.create_geometry_from_file("projector_geometry", "data/objects/projector.obj", avango.gua.LoaderFlags.NORMALIZE_SCALE |
                                                                                                         avango.gua.LoaderFlags.NORMALIZE_POSITION | 
                                                                                                         avango.gua.LoaderFlags.LOAD_MATERIALS  )
    self.geometry.Transform.value = avango.gua.make_scale_mat(0.1)
    self.group_node.Children.value.append(self.geometry)

    self.screen = avango.gua.nodes.ScreenNode(
      Name = "screen1",
      Width = 0.4,
      Height = 0.4,
      Transform = avango.gua.make_trans_mat(0.0, 0.0, -1.0)
    )
    self.group_node.Children.value.append(self.screen)

    self.cam = avango.gua.nodes.CameraNode(
      LeftScreenPath = "projector_group/screen1",
      SceneGraph = "scene",
    )
    self.group_node.Children.value.append(self.cam)

    self.Material.value = avango.gua.nodes.Material(
      ShaderName = "proj_mat"
    )

    self.Graph.value = avango.gua.nodes.SceneGraph(Name = "dummy")

    proj_mat_desc = avango.gua.nodes.MaterialShaderDescription()
    proj_mat_desc.load_from_file("data/materials/Projective_VT_Material.gmd")
    # proj_mat_desc.EnableVirtualTexturing.value = True
    avango.gua.register_material_shader(proj_mat_desc, "proj_mat")


  def set_scenegraph(self, graph):
    self.graph = graph

  @field_has_changed(Transform)
  def update_matrices(self):
    frustum = self.cam.get_frustum(self.Graph.value, avango.gua.CameraMode.CENTER)

    projection_matrix = frustum.ProjectionMatrix.value
    view_matrix = frustum.ViewMatrix.value
    
    self.Material.value.set_uniform("projective_texture_matrix", projection_matrix)
    self.Material.value.set_uniform("view_texture_matrix", view_matrix ) 
    self.Material.value.set_uniform("view_port_min", avango.gua.Vec2(0.1, 0.1))
    # self.Material.value.set_uniform("view_port_max", avango.gua.Vec2(1.0, 1.0))
    self.Material.value.set_uniform("view_port_max", avango.gua.Vec2(0.2, 0.2))
    

  @field_has_changed(Texture)
  def update_texture(self):
    print('updating tex')
    self.Material.value.set_uniform("projective_texture", self.Texture.value)
    self.Material.value.EnableVirtualTexturing.value = True


class AutoVTProjector(avango.script.Script):

  Material = avango.gua.SFMaterial()
  Transform = avango.gua.SFMatrix4()
  Transform2 = avango.gua.SFMatrix4()
  Graph = avango.gua.SFSceneGraph()

  Texture = avango.SFString()

  def __init__(self):
    self.super(AutoVTProjector).__init__()
    self.always_evaluate(False)
    self.is_initialized = False

  def my_constructor(self):
    loader = avango.gua.nodes.TriMeshLoader()

    self.localized_image_list = []
    self.position_list = []
    self.min_tex_coords = avango.gua.Vec2(0.0, 0.0)
    self.max_tex_coords = avango.gua.Vec2(1.0, 1.0)
    self.last_lense_pos = None
    self.scene_graph = None
    self.old_closest_id = 0

    self.group_node = avango.gua.nodes.TransformNode(Name = "projector_group")
    self.group_node.Transform.connect_from(self.Transform)

    self.geometry = loader.create_geometry_from_file("projector_geometry", "data/objects/projector.obj", 
      avango.gua.LoaderFlags.NORMALIZE_SCALE |
      avango.gua.LoaderFlags.NORMALIZE_POSITION | 
      avango.gua.LoaderFlags.LOAD_MATERIALS)
    self.geometry.Transform.value = avango.gua.make_scale_mat(0.1)
    self.group_node.Children.value.append(self.geometry)

    self.screen = avango.gua.nodes.ScreenNode(
      Name = "screen1",
      Width = 0.2,
      Height = 0.2,
      Transform = avango.gua.make_trans_mat(0.0, 0.0, -0.1)
    )
    self.group_node.Children.value.append(self.screen)

    self.cam = avango.gua.nodes.CameraNode(
      LeftScreenPath = "projector_group/screen1",
      # LeftScreenPath = "scene_trans/projector_group/screen1",
      SceneGraph = "scene",
    )
    self.group_node.Children.value.append(self.cam)

    self.Material.value = avango.gua.nodes.Material(
      ShaderName = "proj_mat"
    )

    self.Graph.value = avango.gua.nodes.SceneGraph(Name = "dummy")

    proj_mat_desc = avango.gua.nodes.MaterialShaderDescription()
    proj_mat_desc.load_from_file("data/materials/Projective_VT_Material.gmd")
    # proj_mat_desc.EnableVirtualTexturing.value = True
    avango.gua.register_material_shader(proj_mat_desc, "proj_mat")
    

  def set_scenegraph(self, graph):
    self.scene_graph = graph

  def set_localized_image_list(self, localized_image_list):
    self.localized_image_list = localized_image_list
    self.position_list = [li.position for li in self.localized_image_list]
    print(len(self.localized_image_list), len(self.position_list))
    self.min_tex_coords = self.localized_image_list[self.old_closest_id].min_uv
    self.max_tex_coords = self.localized_image_list[self.old_closest_id].max_uv

  def find_closest_view():
    pass

  @field_has_changed(Transform)
  def update_matrices(self):
    self.group_node.Transform.value = self.Transform.value
    # print('changed', self.Transform.value, self.group_node.Transform.value)
    frustum = self.cam.get_frustum(self.Graph.value, avango.gua.CameraMode.CENTER)

    projection_matrix = frustum.ProjectionMatrix.value
    view_matrix = frustum.ViewMatrix.value
    
    self.Material.value.set_uniform("projective_texture_matrix", projection_matrix)
    # self.Material.value.set_uniform("projective_texture", self.Texture.value)
    self.Material.value.set_uniform("view_texture_matrix", view_matrix) 
    self.Material.value.set_uniform("Emissivity", 1.0)
    self.Material.value.set_uniform("Roughness", 1.0)
    self.Material.value.set_uniform("Metalness", 0.0)
    self.Material.value.set_uniform("view_port_min", avango.gua.Vec2(self.min_tex_coords))
    self.Material.value.set_uniform("view_port_max", avango.gua.Vec2(self.max_tex_coords))

  @field_has_changed(Transform2)
  def updated_lens_position(self):
    if self.last_lense_pos:
      if (self.Transform2.value.get_translate().x != self.last_lense_pos.x
       or self.Transform2.value.get_translate().y != self.last_lense_pos.y 
       or self.Transform2.value.get_translate().z != self.last_lense_pos.z):
        pos = self.Transform2.value.get_translate()

        distance = 10000.0
        closest_id = None
        image_pos = None
        # go through all views and find localized image
        for i_id, i_pos in enumerate(self.position_list):
          new_distance = pu.distance(i_pos, pos)

          if distance > new_distance:
            distance = new_distance
            closest_id = i_id
            image_pos = i_pos

        if closest_id != self.old_closest_id:
          self.localized_image_list[self.old_closest_id].set_selected(False)
          # print('IDs: ',closest_id, self.localized_image_list[closest_id].id)
          # print("Image pos",image_pos, ' distance ',distance," id ", closest_id)
          # print(closest_id, 'before', self.min_tex_coords, self.max_tex_coords)
          # print('setting them to ', self.localized_image_list[closest_id].min_uv, self.localized_image_list[closest_id].max_uv)
          self.Transform.value = self.localized_image_list[closest_id].transform
          self.min_tex_coords = self.localized_image_list[closest_id].min_uv
          self.max_tex_coords = self.localized_image_list[closest_id].max_uv
          self.screen.Width.value = self.localized_image_list[closest_id].tile_w
          self.screen.Height.value = self.localized_image_list[closest_id].tile_h
          # print(self.screen.Width.value, self.screen.Height.value)
          self.localized_image_list[closest_id].set_selected(True)
          self.last_lense_pos = self.Transform2.value.get_translate()
          print(closest_id, self.min_tex_coords, self.max_tex_coords)
          self.old_closest_id = closest_id
          
    else:
      self.last_lense_pos = self.Transform2.value.get_translate()

  @field_has_changed(Texture)
  def update_texture(self):
    print('updating tex')
    self.Material.value.set_uniform("projective_texture", self.Texture.value)
    self.Material.value.EnableVirtualTexturing.value = True

  def evaluate(self):
    pass