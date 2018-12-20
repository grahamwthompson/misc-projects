fn main() {
    println!("Hello, world!");

    another_function(5);

    let x = {
        let y = 5;
        y + 1
    };

    println!("{}", x);

}

fn another_function(x: i32) {
    println!("Another function. {}", x);
}
