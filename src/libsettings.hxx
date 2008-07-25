// This file is part of the libsettings framework.
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
 * \file libsettings.hxx
 *
 * Implement of the Settings class declaration.
 */

#ifndef LIBSETTINGS_HXX
# define LIBSETTINGS_HXX
# include <boost/tokenizer.hpp>

namespace settings
{
  template <typename ValueType>
  Settings<ValueType>::Settings () throw  ()
    : settings_ ()
  {
  }

  template <typename ValueType>
  Settings<ValueType>::~Settings () throw  ()
  {
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::value_type&
  Settings<ValueType>::operator[]
  (const typename Settings<ValueType>::key_type& key)
  {
    return settings_[key];
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::iterator
  Settings<ValueType>::begin ()
  {
    return settings_.begin ();
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::const_iterator
  Settings<ValueType>::begin () const
  {
    return settings_.begin ();
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::iterator
  Settings<ValueType>::end ()
  {
    return settings_.end ();
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::const_iterator
  Settings<ValueType>::end () const
  {
    return settings_.end ();
  }

//   template <typename ValueType>
//   inline typename Settings<ValueType>::reverse_iterator
//   Settings<ValueType>::rbegin ()
//   {
//     return settings_.rbegin ();
//   }

//   template <typename ValueType>
//   inline typename Settings<ValueType>::const_reverse_iterator
//   Settings<ValueType>::rbegin () const
//   {
//     return settings_.rbegin ();
//   }

//   template <typename ValueType>
//   inline typename Settings<ValueType>::reverse_iterator
//   Settings<ValueType>::rend ()
//   {
//     return settings_.rend ();
//   }

//   template <typename ValueType>
//   inline typename Settings<ValueType>::const_reverse_iterator
//   Settings<ValueType>::rend () const
//   {
//     return settings_.rend ();
//   }

  template <typename ValueType>
  inline bool
  Settings<ValueType>::empty () const
  {
    return settings_.empty ();
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::size_type
  Settings<ValueType>::size () const
  {
    return settings_.size ();
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::size_type
  Settings<ValueType>::max_size () const
  {
    return settings_.max_size ();
  }

  template <typename ValueType>
  inline std::pair<typename Settings<ValueType>::iterator, bool>
  Settings<ValueType>::insert
  (const typename Settings<ValueType>::value_type& x)
  {
    return settings_.insert (x);
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::iterator
  Settings<ValueType>::insert
  (typename Settings<ValueType>::iterator position,
   const typename Settings<ValueType>::value_type& x)
  {
    return settings_.insert (position, x);
  }

  template <typename ValueType>
  template <typename InputIterator>
  inline void
  Settings<ValueType>::insert (InputIterator first, InputIterator last)
  {
    return settings_.insert (first, last);
  }

  template <typename ValueType>
  inline void
  Settings<ValueType>::erase (iterator position)
  {
    return settings_.erase (position);
  }

  template <typename ValueType>
  inline typename Settings<ValueType>::size_type
  Settings<ValueType>::erase (const typename Settings<ValueType>::key_type& x)
  {
    return settings_.erase (x);
  }

  template <typename ValueType>
  inline void
  Settings<ValueType>::erase (typename Settings<ValueType>::iterator first,
                              typename Settings<ValueType>::iterator last)
  {
    return settings_.erase (first, last);
  }

  template <typename ValueType>
  inline void
  Settings<ValueType>::swap (typename Settings<ValueType>::HashMap_t& mp)
  {
    return settings_.swap (mp);
  }

  template <typename ValueType>
  inline void
  Settings<ValueType>::clear ()
  {
    settings_.clear ();
  }

//   template <typename ValueType>
//   typename Settings<ValueType>::key_compare
//   Settings<ValueType>::key_comp () const
//   {
//     return settings_.key_comp ();
//   }

//   template <typename ValueType>
//   typename Settings<ValueType>::value_compare
//   Settings<ValueType>::value_comp () const
//   {
//     return settings_.value_comp ();
//   }

  template <typename ValueType>
  typename Settings<ValueType>::iterator
  Settings<ValueType>::find (const typename Settings<ValueType>::key_type& x)
  {
    return settings_.find (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::const_iterator
  Settings<ValueType>::find
  (const typename Settings<ValueType>::key_type& x) const
  {
    return settings_.find (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::size_type
  Settings<ValueType>::count
  (const typename Settings<ValueType>::key_type& x) const
  {
    return settings_.count (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::iterator
  Settings<ValueType>::lower_bound (const key_type& x)
  {
    return settings_.lower_bound (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::const_iterator
  Settings<ValueType>::lower_bound (const key_type& x) const
  {
    return settings_.lower_bound (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::iterator
  Settings<ValueType>::upper_bound (const key_type& x)
  {
    return settings_.upper_bound (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::const_iterator
  Settings<ValueType>::upper_bound (const key_type& x) const
  {
    return settings_.upper_bound (x);
  }

  template <typename ValueType>
  std::pair<typename Settings<ValueType>::iterator,
            typename Settings<ValueType>::iterator>
  Settings<ValueType>::equal_range
  (const typename Settings<ValueType>::key_type& x)
  {
    return settings_.equal_range (x);
  }

  template <typename ValueType>
  std::pair<typename Settings<ValueType>::const_iterator,
            typename Settings<ValueType>::const_iterator>
  Settings<ValueType>::equal_range
  (const typename Settings<ValueType>::key_type& x) const
  {
    return settings_.equal_range (x);
  }

  template <typename ValueType>
  typename Settings<ValueType>::allocator_type
  Settings<ValueType>::get_allocator () const
  {
    return settings_.get_allocator ();
  }

} // end of namespace settings.

#endif //! LIBSETTINGS_HXX
