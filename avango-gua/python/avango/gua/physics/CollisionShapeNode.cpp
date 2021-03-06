#include "CollisionShapeNode.hpp"

#include <boost/python.hpp>
#include <avango/python/register_field.h>
#include <avango/gua/physics/CollisionShapeNode.hpp>

using namespace boost::python;
using namespace av::python;

namespace boost
{
namespace python
{
template <class T>
struct pointee<av::Link<T>>
{
    using type = T;
};
} // namespace python
} // namespace boost

void init_CollisionShapeNode()
{
    register_ptr_to_python<av::Link<av::gua::CollisionShapeNode>>();
    register_field<av::gua::SFCollisionShapeNode>("SFCollisionShapeNode");
    register_multifield<av::gua::MFCollisionShapeNode>("MFCollisionShapeNode");

    class_<av::gua::CollisionShapeNode, av::Link<av::gua::CollisionShapeNode>, bases<av::gua::TransformNode>, boost::noncopyable>("CollisionShapeNode", "docstring", no_init);
}
