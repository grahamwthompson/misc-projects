fn main() {
    let s: String = String::from("hello buddy");
    let slice1 = &s[0..5];
    let slice2: &str = &s[0..5];  // so this is a little weird string slices
    // are of type &str rather than String, or anything whats with that?

    println!("{}", slice1);


    let a = [1,2,3,4,5];
    println!("{}", a[0]);

}
