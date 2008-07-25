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
 * \file simple.cc
 *
 * Test case using simple types (int, string).
 */

#include <iostream>
#include <string>

#include <libsettings.hh>
#include <libsettings-values.hh>

int main ()
{
  {
    typedef int settingsType;

    settings::Settings<settingsType> settings;

    settings["foo"] = 1;
    settings["bar"] = 2;
    settings["baz"] = 3;

    std::cout << settings["foo"] << std::endl
              << settings["bar"] << std::endl
              << settings["baz"] << std::endl;

    settings["foo"] = settings["bar"] + settings["baz"];

    std::cout << settings["foo"] << std::endl
              << settings["bar"] << std::endl
              << settings["baz"] << std::endl;
  }

  {
    typedef std::string settingsType;

    settings::Settings<settingsType> settings;

    settings["module.bla"] = "bla";
    settings["abcd.bar"] = "bla1";
    settings["baz"] = "bla2";

    for (settings::Settings<settingsType>::iterator it = settings.begin ();
         it != settings.end (); ++it)
      std::cout << it->first << ": " << it->second << std::endl;
  }
}
