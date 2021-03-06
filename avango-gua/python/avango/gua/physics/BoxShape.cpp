#include "BoxShape.hpp"

#include <boost/python.hpp>
#include <avango/python/register_field.h>
#include <avango/gua/physics/BoxShape.hpp>

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

void init_BoxShape()
{
    register_ptr_to_python<av::Link<av::gua::BoxShape>>();

    register_field<av::gua::SFBoxShape>("SFBoxShape");
    register_multifield<av::gua::MFBoxShape>("MFBoxShape");

    class_<av::gua::BoxShape, av::Link<av::gua::BoxShape>, bases<av::gua::CollisionShape>, boost::noncopyable>("BoxShape", "docstring", no_init);
}
