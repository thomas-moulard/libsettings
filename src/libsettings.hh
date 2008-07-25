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
 * \file libsettings.hh
 *
 * Contain the Settings class declaration.
 */

#ifndef LIBSETTINGS_HH
# define LIBSETTINGS_HH
# include <ext/hash_map>
# include <string>
# include <vector>

//FIXME: include pair

# include <libsettings-fwd.hh>

namespace settings
{
  namespace detail
  {
    struct hash
    {
      size_t operator() (const std::string& x) const
      {
        return __gnu_cxx::hash<const char*> () (x.c_str ());
      }
    };
  } // end of namespace detail

  template <typename ValueType>
  class Settings
  {
  public:
    typedef __gnu_cxx::hash_map<std::string,
                                ValueType,
                                detail::hash> HashMap_t;

    typedef ValueType value_type;

    typedef typename HashMap_t::key_type key_type;
    typedef typename HashMap_t::mapped_type mapped_type;
    // typedef typename HashMap_t::key_compare key_compare;
    // typedef typename HashMap_t::value_compare value_compare;
    typedef typename HashMap_t::allocator_type allocator_type;
    typedef typename HashMap_t::reference reference;
    typedef typename HashMap_t::const_reference const_reference;
    typedef typename HashMap_t::iterator iterator;
    typedef typename HashMap_t::const_iterator const_iterator;
    typedef typename HashMap_t::size_type size_type;
    typedef typename HashMap_t::difference_type difference_type;
    typedef typename HashMap_t::pointer pointer;
    typedef typename HashMap_t::const_pointer const_pointer;
    // typedef typename HashMap_t::reverse_iterator reverse_iterator;
    // typedef typename HashMap_t::const_reverse_iterator const_reverse_iterator;

    explicit Settings () throw  ();
    virtual ~Settings () throw  ();

    value_type& operator[] (const key_type&);

    iterator begin ();
    const_iterator begin () const;
    iterator end ();
    const_iterator end () const;

//     reverse_iterator rbegin ();
//     const_reverse_iterator rbegin () const;
//     reverse_iterator rend ();
//     const_reverse_iterator rend () const;

    bool empty () const;
    size_type size () const;
    size_type max_size () const;

    std::pair<iterator,bool> insert (const value_type& x);
    iterator insert (iterator position, const value_type& x);
    template <class InputIterator>
    void insert (InputIterator first, InputIterator last);

    void erase (iterator position);
    size_type erase (const key_type& x);
    void erase (iterator first, iterator last);

    void swap (HashMap_t& mp);

    void clear ();

    // key_compare key_comp () const;
    // value_compare value_comp () const;

    iterator find (const key_type& x);
    const_iterator find (const key_type& x) const;

    size_type count (const key_type& x) const;

    iterator lower_bound (const key_type& x);
    const_iterator lower_bound (const key_type& x) const;

    iterator upper_bound (const key_type& x);
    const_iterator upper_bound (const key_type& x) const;

    std::pair<iterator,iterator>
    equal_range (const key_type& x);
    std::pair<const_iterator,const_iterator>
    equal_range (const key_type& x) const;

    allocator_type get_allocator() const;

  private:
    HashMap_t settings_;
  };

} // end of namespace settings.

# include <libsettings.hxx>
#endif //! LIBSETTINGS_HH
