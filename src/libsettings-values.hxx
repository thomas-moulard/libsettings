// This file is part of the libsettings.
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
 * \file libsettings-values.hxx
 *
 * Implementation of values types for settings.
 */

#ifndef LIBSETTINGS_VALUES_HXX
# define LIBSETTINGS_VALUES_HXX

# include <boost/type_traits/is_const.hpp>

namespace settings
{
  template <typename ValueType, typename MetaInformation>
  Value<ValueType, MetaInformation>::Value (std::string n,
                                            ValueType v,
                                            readHook_t rh,
                                            writeHook_t wh)
    : name (n),
      value (v),
      readHook (rh),
      writeHook (wh)
  {}

  template <typename ValueType, typename MetaInformation>
  Range<ValueType, MetaInformation>::Range (std::string n,
                                            ValueType v,
                                            typename parent_t::readHook_t rh,
                                            typename parent_t::writeHook_t wh)
    : Value<ValueType, MetaInformation> (n, v, rh, wh)
  {}

  template <typename MetaInformation>
  Action<MetaInformation>::Action (std::string n,
                                   typename parent_t::readHook_t rh,
                                   typename parent_t::writeHook_t wh)
    : Value<bool, MetaInformation> (n, false, rh, wh)
  {}

  template <typename MetaInformation>
  Menu<MetaInformation>::Menu (std::string n)
    : Value<std::vector<std::string>, MetaInformation> (n)
  {}


  template <typename T>
  AccessNotifier<T>::AccessNotifier (T& t)
    : t_ (t)
  {}

  namespace detail
  {
    // Not const: call the write hook.
    template <typename T>
    void
    notifyWrite (T& t, const boost::false_type&)
    {
      t.writeHook (t.value);
    }

    // Const: do nothing.
    template <typename T>
    void
    notifyWrite (T&, const boost::true_type&)
    {}

  } // end of namespace detail

  template <typename T>
  AccessNotifier<T>::~AccessNotifier ()
  {
    detail::notifyWrite (t_, boost::is_const<value_type> ());
  }

  template <typename T>
  T&
  AccessNotifier<T>::operator* ()
  {
    t_.readHook ();
    return t_;
  }

  template <typename T>
  T*
  AccessNotifier<T>::operator-> ()
  {
    t_.readHook ();
    return &t_;
  }

  template <typename T>
  const T&
  AccessNotifier<T>::operator* () const
  {
    t_.readHook ();
    return t_;
  }

  template <typename T>
  const T*
  AccessNotifier<T>::operator-> () const
  {
    t_.readHook ();
    return &t_;
  }
} // end of namespace settings.

# include <libsettings-values.hxx>
#endif //! LIBSETTINGS_VALUES_HXX
