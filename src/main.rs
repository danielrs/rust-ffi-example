// The wrapper around our C library.
extern crate sort;
use sort::*;

fn main() {
    let mut int_arr = vec![-10, 5, 2, 10, -10];
    let mut float_arr = vec![-10.25, 5.5, 2.0, 5.6, 10.0, -10.5, -11.11];
    let mut char_arr = vec!['a', 'g', 'z', 'b', 'c', 'c', 'd', 'p', 'o'];

    extern fn ascending<T>(a: &T, pivot: &T) -> i32
        where T: PartialOrd {
        if *a < *pivot { - 1 }
        else if *a == *pivot { 0 }
        else { 1 }
    }

    extern fn descending<T>(a: &T, pivot: &T) -> i32
        where T: PartialOrd {
        -ascending(a, pivot)
    }

    int_arr.sort_by(ascending);
    float_arr.sort_by(descending);
    char_arr.sort_by(ascending);

    println!("{:?}", int_arr);
    println!("{:?}", float_arr);
    println!("{:?}", char_arr);
}
