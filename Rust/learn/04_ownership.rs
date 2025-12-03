fn main(){
    // 变量作用域
    // let s = "hello";
    // println!("s is {}", s);

    // {
    //     let s1 = "hi";
    //     println!("s is {}", s);
    //     println!("s1 is {}", s1);
    // }

    // println!("s1 is {}", s1);

    // let mut s = String::from("hello");

    // println!("s is {}", s);

    // s.push_str(", world!");

    // println!("s is {}", s);



    // let x = 5;
    // let y = x;
    // println!("x = {}", x);
    // println!("y = {}", y);



    // let s1 = String::from("hello");
    // println!("s1 is {}", s1);
    // let s2 = s1;
    // println!("s2 is {}", s2);
    // println!("s1 is {}", s1);

    // let s1 = String::from("hello");
    // let s2 = s1.clone();
    // println!("s1 is {}, s2 is {}", s1, s2);



    // 所有权与函数
    // let s = String::from("hello");

    // takes_ownership(s);
    // // println!("{}", s);

    // let x = 5;

    // makes_copy(x);
    // println!("{}", x);



    // let s1 = gives_ownership();
    // println!("s1 is {}", s1);

    // let s2 = String::from("hello");

    // let s3 = takes_and_gives_back(s2);
    // println!("s3 is {}", s3);

    


    let s1 = String::from("hello");

    let (s2, len) = calculate_length(s1);

    println!("The length of '{}' is {}.", s2, len);
}

fn calculate_length(s: String) -> (String, usize){
    let length = s.len();

    (s, length)
}

// fn gives_ownership() -> String{
//     let some_string = String::from("yours");

//     some_string
// }

// fn takes_and_gives_back(a_string: String) -> String{
//     a_string
// }

// fn takes_ownership(some_string: String){
//     println!("{}", some_string);
// }

// fn makes_copy(some_integer: i32){
//     println!("{}", some_integer);
// }