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

#ifndef shade_parser_FunctionHandler_H
#define shade_parser_FunctionHandler_H

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <string>
#include <vector>

namespace shade
{
namespace parser
{
class Segment;

typedef std::vector<std::string>::const_iterator ParameterIterator;
typedef boost::function<void(
    const std::string& name, ParameterIterator begin, ParameterIterator end, const std::string& return_type, const std::string& parameters, boost::shared_ptr<Segment> segment)>
    FunctionHandler;
} // namespace parser
} // namespace shade

#endif /* shade_parser_FunctionHandler_H */
