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

#ifndef shade_formatter_FileMark
#define shade_formatter_FileMark shade_formatter_FileMark

#include "Mark.h"
#include <string>

namespace shade
{
namespace formatter
{
class FileMark : public Mark
{
  public:
    FileMark(void);
    FileMark(const std::string& filename, unsigned int line_number = 0);

    const std::string& get_filename(void) const { return m_filename; }
    unsigned int get_line_number(void) const { return m_line_number; }

  private:
    const std::string m_filename;
    const unsigned int m_line_number;
};
} // namespace formatter
} // namespace shade

#endif /* shade_formatter_FileMark */
