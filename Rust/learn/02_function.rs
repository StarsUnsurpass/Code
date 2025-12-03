fn main(){
    // println!("this is a main function");

    // another_function();

    // print_num(3241);

    // 语句和表达式
    /*
    * 表达式可以是语句的一部分：语句 let y = 6; 中的 6 是一个表达式，
    * 函数调用是一个表达式
    * 宏调用是一个表达式
    * 创建新作用域的大括号（代码块） {} 也是一个表达式
    */
    let y = {
        let x = 5;
        x + 1
    };
    println!("y is {}", y);
}

// 在函数签名中，必须声明每个参数的类型
// fn print_num(num: i32){
//     println!("the number is {}", num);
// }

// Rust 不关心函数定义于何处，只要定义了就行
// fn another_function(){
//     println!("this is another function");
// }