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
 * \file access-notifiers.cc
 *
 * Test case using AccessNotifiers with read/write hooks.
 */

#include <iostream>
#include <string>

#include <libsettings.hh>
#include <libsettings-values.hh>

void readMe ()
{
  std::cout << "read!" << std::endl;
}

void writeMe (int)
{
  std::cout << "write!" << std::endl;
}

//FIXME: fix that!
int main ()
{
  using namespace settings;
  typedef AccessNotifier<Value<int, DefaultMetaInformation> > settingsType;

  Settings<settingsType> settings;

//   settings["b"] = Value<int, DefaultMetaInformation> (...);

//   for (settings::Settings<settingsType>::iterator it = settings.begin ();
//        it != settings.end (); ++it)
//     std::cout << it->first << ": " << it->second << std::endl;
}
