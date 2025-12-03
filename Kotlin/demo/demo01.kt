fun main(){
    // println("Please enter a word:");

    // val yourWord = readln()

    // print("Your word is:")
    // println(yourWord)

    // println("sun of 435 and 8596 is ${sum(435, 8596)}")
    // println("square of 45 is ${square(45)}")

    printSum(4325, 8936)
    val a:Int = 31
    val b:Int = 13
    printSum(a, b)
}

fun printSum(a: Int, b: Int): Unit{
    println("sum of $a and $b is ${a + b}")
}

fun sum(a: Int, b: Int): Int{
    return a + b
}

fun square(a: Int) = a * a