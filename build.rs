extern crate gcc;

fn main() {
    gcc::compile_library("libsort.a", &["lib/sort.c"]);
}
