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
 * \file libsettings-values.hh
 *
 * Declaration of values types for settings.
 */

#ifndef LIBSETTINGS_VALUES_HH
# define LIBSETTINGS_VALUES_HH
# include <string>
# include <vector>

# include <boost/function.hpp>

namespace settings
{
  /// \brief Default meta-information
  /// Meta-information classes are used to
  /// add additional information.
  struct DefaultMetaInformation
  {
    /// User-oriented description.
    std::string userDescription;

    /// \brief Linked setting
    /// If this property is set to true,
    /// it means that changing this setting
    /// may also change other settings.
    /// It means that other settings should be
    /// refreshed after modifying this one (like
    /// by recreating the user-interface).
    bool linkedSetting;
  };

  /// The value class encapsulate a data into a class
  /// and associates it to a key and meta-information.
  template <typename ValueType, typename MetaInformation>
  struct Value : public MetaInformation
  {
    /// Type of the encapsulated value.
    typedef ValueType value_type;

    /// Read hook type.
    typedef boost::function<void ()> readHook_t;

    /// Write hook type.
    typedef boost::function<void (const value_type&)> writeHook_t;

    /// Initialize both key and value.
    explicit Value (std::string n,
                    ValueType v = ValueType (),
                    readHook_t wh = readHook_t (),
                    writeHook_t wh = writeHook_t ());

    /// Associated key (i.e. ``setting name'')
    const std::string name;

    /// Setting value.
    ValueType value;

    /// Read hook.
    readHook_t readHook;

    /// Write hook.
    writeHook_t writeHook;
  };

  /// The range class encapsulates a range.
  /// It contains a minimum, maximum and a step value.
  template <typename ValueType, typename MetaInformation>
  struct Range : public Value<ValueType, MetaInformation>
  {
    typedef Value<ValueType, MetaInformation> parent_t;

    explicit Range (std::string n,
                    ValueType v = ValueType (),
                    typename parent_t::readHook_t rh =
                    typename parent_t::readHook_t (),
                    typename parent_t::writeHook_t wh =
                    typename parent_t::writeHook_t ());

    ValueType minimum;
    ValueType maximum;
    ValueType step;
  };

  /// \brief Encapsulate a setting which is an action.
  /// i.e. which does not really contain a value
  /// but triggers an action.
  /// It is basically a subclass of Value<bool>
  /// (typedef has been avoided here to be able
  ///  to discriminate the type).
  template <typename MetaInformation>
  struct Action : public Value<bool, MetaInformation>
  {
    typedef Value<bool, MetaInformation> parent_t;

    explicit Action (std::string n,
                     typename parent_t::readHook_t rh =
                     typename parent_t::readHook_t (),
                     typename parent_t::writeHook_t wh =
                     typename parent_t::writeHook_t ());
  };

  /// Encapsulates a menu (a list of choices indexed by an integer).
  template <typename MetaInformation>
  struct Menu : public Value<std::vector<std::string>, MetaInformation>
  {
    explicit Menu (std::string n);
  };

  /// Trigger reading and writing hooks if available.
  template <typename T>
  class AccessNotifier
  {
  public:
    typedef T value_type;

    explicit AccessNotifier (value_type& t);
    ~AccessNotifier ();
    value_type& operator* ();
    value_type* operator-> ();
    const value_type& operator* () const;
    const value_type* operator-> () const;

  private:
    value_type& t_;
  };
} // end of namespace settings.

# include <libsettings-values.hxx>
#endif //! LIBSETTINGS_VALUES_HH
