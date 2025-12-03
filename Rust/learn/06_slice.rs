fn main(){
    // let s = String::from("hello world");

    // let hello = &s[0..5];
    // let world = &s[6..11];

    // println!("{}", hello);
    // println!("{}", world);




    // let s = String::from("hello");

    // let slice1 = &s[0..2];
    // let slice2 = &s[..2];

    // let len = s.len();
    // let slice3 = &s[3..len];
    // let slice4 = &s[3..];

    // let slice5 = &s[0..len];
    // let slice6 = &s[..];




    // let s = String::from("hello world");
    // let first_of_s = first_word(&s);
    // println!("{}", first_of_s);




    // let s = String::from("hello world");
    // let first_of_s = first_word(&s);
    // s.clear();
    // println!("{}", first_of_s);




    // 字符串字面量是slice
    // 这里 s 的类型是 &str：它是一个指向二进制程序特定位置的 slice。
    // 这也就是为什么字符串字面量是不可变的；&str 是一个不可变引用。
    // let s = "hello world";




    // let my_string = String::from("hello world");

    // let word1 = first_word(&my_string[0..6]);
    // let word2 = first_word(&my_string[..]);
    // let word3 = first_word(&my_string);

    // let my_string_literal = "hello world";

    // let word4 = first_word(&my_string_literal[0..6]);
    // let word5 = first_word(&my_string_literal[..]);
    // let word6 = first_word(my_string_literal);




    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];

    for elements in slice{
        print!("{} ", elements);
    }
    println!();
}




// fn first_word(s: &str) -> &str{
//     let bytes = s.as_bytes();

//     for(i, &item) in bytes.iter().enumerate(){
//         if item == b' '{
//             return &s[0..i];
//         }
//     }

//     &s[..]
// }


// fn first_word(s: &String) -> &str{
//     let bytes = s.as_bytes();

//     for(i, &item) in bytes.iter().enumerate(){
//         if item == b' '{
//             return &s[0..i];
//         }
//     }

//     &s[..]
// }


// fn first_word(s: &String) -> usize{
//     let bytes = s.as_bytes();

//     for(i, &item) in bytes.iter().enumerate(){
//         if item == b' '{
//             return i;
//         }
//     }

//     s.len();
// }