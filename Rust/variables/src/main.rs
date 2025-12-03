fn main() {
    // let mut x = 5;
    // println!("The value of x is: {}", x);

    // x = 6;
    // println!("The value of x is: {}", x);

    // const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
    // println!("three hours in seconds is: {}", THREE_HOURS_IN_SECONDS);

    // let y = 5;
    
    // let y = y + 1;

    // {
    //     let y = y * 2;
    //     println!("The value of y in the inner scope is: {}", y);
    // }

    // println!("The value of y is: {}", y);

    // let spaces = "    ";
    // let spaces = spaces.len();
    // println!("The length of spaces is: {}", spaces);


    let guess: u32 = "42".parse().expect("Not a number!");
    println!("{}", guess);
}
