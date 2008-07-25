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
 * \file libsettings-fwd.hh
 *
 * Forward declarations.
 */

#ifndef LIBSETTINGS_FWD_HXX
# define LIBSETTINGS_FWD_HXX

namespace settings
{
  template <typename ValueType>
  class Settings;

  class DefaultMetaInformation;

  template <typename ValueType, typename MetaInformation>
  class Value;

  template <typename ValueType, typename MetaInformation>
  class Range;

  template <typename MetaInformation>
  class Action;

  template <typename MetaInformation>
  class Menu;

  template <typename T>
  class AccessNotifier;

} // end of namespace settings.

#endif //! LIBSETTINGS_FWD_HXX
