// This file is part of the libsettings library.
//
// libsettings is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libsettings is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libsettings.  If not, see <http://www.gnu.org/licenses/>.

/*
 * \file variant.cc
 *
 * Test case using Boost.Variant.
 */

#include <iostream>
#include <string>

#include <libsettings.hh>
#include <libsettings-values.hh>

#include <boost/variant.hpp>

int main ()
{
  typedef boost::variant<long, double, std::string> settingsType;

  settings::Settings<settingsType> settings;

  settings["a"] = "bla";
  settings["b"] = 3.14;
  settings["c"] = 42l;

  settings["a"] = 2.1;
  settings["b"] = "baz";

  for (settings::Settings<settingsType>::iterator it = settings.begin ();
       it != settings.end (); ++it)
    std::cout << it->first << ": " << it->second << std::endl;
}
