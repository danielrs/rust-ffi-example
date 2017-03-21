extern crate libc;

mod ffi;

use libc::{c_void, c_int};
use std::mem;

/// Trait for types that can be sorted.
pub trait SortBy<T> {
    /// Sorts the Self using the comparator function.
    fn sort_by(&mut self, compare: extern fn(&T, &T) -> c_int);
}

// Implement sort for Vector.
impl<T> SortBy<T> for Vec<T> {
    fn sort_by(&mut self, compare: extern fn(&T, &T) -> c_int) {
        unsafe {
            ffi::quicksort(
                self.as_mut_ptr() as *mut c_void,
                0,
                self.len() as c_int,
                mem::size_of::<T>(),
                mem::transmute(compare)
            );
        }

    }
}
