// -*- Mode:C++ -*-

/************************************************************************\
*                                                                        *
* This file is part of AVANGO.                                           *
*                                                                        *
* Copyright 2007 - 2010 Fraunhofer-Gesellschaft zur Foerderung der       *
* angewandten Forschung (FhG), Munich, Germany.                          *
*                                                                        *
* AVANGO is free software: you can redistribute it and/or modify         *
* it under the terms of the GNU Lesser General Public License as         *
* published by the Free Software Foundation, version 3.                  *
*                                                                        *
* AVANGO is distributed in the hope that it will be useful,              *
* but WITHOUT ANY WARRANTY; without even the implied warranty of         *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
* GNU General Public License for more details.                           *
*                                                                        *
* You should have received a copy of the GNU Lesser General Public       *
* License along with AVANGO. If not, see <http://www.gnu.org/licenses/>. *
*                                                                        *
\************************************************************************/

#include <shade/types/const.h>

shade::const_::const_(formatter::Constants::Type type) : Type(type) {}

bool shade::const_::requires_initializer(void) const { return true; }

bool shade::const_::is_writable(const ShaderEnvironment& se) const { return false; }

void shade::const_::output_attribute(boost::shared_ptr<Type::State> state, Formatter* fmt, const std::string& obj, const std::string& name) const
{
    boost::shared_ptr<formatter::Generator> generator(fmt->begin_insert_init_attribute(m_type, obj, name, formatter::Constants::const_));
    this->generate_constructor(*generator, state);
    fmt->end_insert_init_attribute();
}

std::string shade::const_::get_uniq_id(void) const { return "const"; }
