fn main() {

    let mut x:u32 = 1;
    let sum = loop {
        x = x + x;
        if x >= 100 {
            break x
        }
    };

    println!("Loop output: {}", x);

    for n in 1..4 {
        println!("{}", n);
    }

    x = 1..4;


}
