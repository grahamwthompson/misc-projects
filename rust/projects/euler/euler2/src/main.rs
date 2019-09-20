static MAX:u32 = 4000000;

fn fib() -> u32 {
    let (mut a, mut b, mut temp):(u32,u32,u32) = (1,2,0);
    let mut sum:u32 = 0; // initialize with a
    
    while(b <= MAX) {
        if b % 2 == 0 {
            sum += b;
        }
        temp = a;
        a = b;
        b = b + temp;
    }
    sum
}

fn main() {
    println!("Even sum = {}", fib());

}
