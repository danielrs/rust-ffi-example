use libc::{c_void, c_int, size_t};

#[link(name="sort")]
extern {
    pub fn quicksort(
        arr: *mut c_void,
        begin: c_int,
        end: c_int,
        item_size: size_t,
        cmp: extern fn(*const c_void, *const c_void) -> c_int
    );
}
