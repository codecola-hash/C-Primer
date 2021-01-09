#### 习题6.1

> 实参和形参的区别是什么？

实参时函数调用时的实际参数，是形参的初始值。

#### 习题6.2

> 指出下列函数那个有错误？为什么？如何修改

```c++
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x;
```

> 修改之后：

```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  { return x * x };
```

#### 习题6.3

> 编写你自己的fact函数，上机检查是否正确。

#### 习题6.4

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

#### 习题6.5

> 编写一个函数输出其实参的绝对值。

```c++
int abs_my(const int & nNumber)
{
    return nNumber > 0 ? nNumber : -nNumber;
}
```

#### 习题6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。
>
> **形参**定义在函数的参数列表中；**局部变量**定义在函数块内部，两者的生命周期均为函数调用期间。**局部静态变量**定义在函数内部，但其生命周期为整个程序运行期间。

```c++
int add_count(const int &nCount)  // nCount是形参
{
    static int all_count = 0;     // 静态局部变量
    all_count += nCount;

    int ret = all_count;          // 局部变量

    return ret;
}

int main()
{
    std::cout << add_count(5) << std::endl;

    return 0;
}
```

#### 习题6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```c++
int add()
{
    static int nCount = 0;
    return ++nCount;
}
```

#### 习题6.8

> 编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。

#### 习题6.9

> 编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

#### 习题6.10

> 编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

#### 习题6.11

> 编写并验证你自己的reset函数，使其作用于引用类型的参数。

```c++
void reset(int &n)
{
    n = 0;
}
```

#### 习题6.12

> 改写6.2.1节练习中的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
>
> 明显引用更好。

#### 习题6.13

> 假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。

- `void f(T)` 的参数通过值传递，在函数中 T 是实参的副本，改变T不会影响到原来的实参。
- `void f(&T)` 的参数通过引用传递，在函数中的T是实参的引用，T的改变也就是实参的改变。

#### 习题6.14

> 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

> 例如交换两个参数的值，形参应该是引用
>
> 若是实参是右值，则不能使用引用作为形参

#### 习题6.15

> 说明find_char 函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

- 因为字符串可能很长，因此使用引用避免拷贝；而在函数中我们不希望改变 s 的内容，所以令 s 为常量。
- occurs 是要传到函数外部的变量，所以使用引用，occurs 的值会改变，所以是普通引用。
- 因为我们只需要 c 的值，这个实参可能是右值(右值实参无法用于引用形参)，所以 c 不能用引用类型。
- 如果 s 是普通引用，也可能会意外改变原来字符串的内容。
- occurs 如果是常量引用，那么意味着不能改变它的值，那也就失去意义了。

#### 习题6.16

> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。

```cpp
bool is_empty(string& s) { return s.empty(); }
```

上述代码的局限性在于，函数无法接受字面值/常量字符串，同时在函数内部`s`还有被改变的风险。例如如下调用都是错误的

```cpp
const string str;
bool flag = is_empty(str); //非法
bool flag = is_empty("hello"); //非法
```

所以我们应该这样修改：

```cpp
bool is_empty(const string& s) { return s.empty(); }
```

#### 习题6.17

> 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

不一样，第一个函数入参不需要修改且为了避免拷贝，使用常量引用。第二个参数因为要修改，因此采用普通引用。

#### 习题6.18

> 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。

- (a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。
- (b) 名为 change_val 的函数，返回vector的迭代器，有两个参数：一个是int，另一个是vector的迭代器。

```c++
bool compare(const matrix &first, const matrix &senond);
std::vector<int>::iterator change_val(int n, std::vector<int>::iterator iter);
```

#### 习题6.19

> 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。

```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```

- (a)不合法，函数入参多了一个
- (b)合法
- (c)合法
- (d)合法，但会发生精度损失。

#### 习题6.20

> 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

不需要实参发生改变时，应该使用常量引用。

若设为了普通引用，会使函数可接受的数据类型变少，也会因为意外改变实参使程序出错。

#### 习题6.21

> 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

```c++
int max(const int &nFirst, const int *pnSecond)
{
    return nFirst > *pnSecond ? nFirst : *pnSecond;
}
```

指针的类型应该为 `const int *`。

#### 习题6.22

> 编写一个函数，令其交换两个int指针。

```c++
void swap(int * const pnFirst, int * const pnSecond)
{
    int ntemp = *pnFirst;

    *pnFirst = *pnSecond;
    *pnSecond = ntemp;
}
```

#### 习题6.23

> 参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:

#### 习题6.24

> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

```c++
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

传入数组时，该函数会自动将数组的首地址赋值给ia，此时会发生编译错误。

修改办法：将函数入参改为  `const int (&ia)[]`

#### 习题6.25

> 编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。

#### 习题6.26

> 编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。

#### 习题6.27

> 编写一个函数，它的参数是initializer_list类型的对象，函数的功能是计算列表中所有元素的和。

#### 习题6.28

> 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？

是`const ErrCode&` 类型

#### 习题6.29

> 在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

应该使用常量引用类型，因为`initializer_list`内部的元素无法更改。

#### 习题6.30

> 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

错误信息（vs2017）：

> 错误 1 error C2561: “str_subrange”: 函数必须返回值

#### 习题6.31

> 什么情况下返回的引用无效？什么情况下返回常量的引用无效？

当返回的引用绑定的是局部对象时，返回的引用无效。当我们需要返回的引用可以修改时，返回的常量引用无效。

#### 习题6.32

> 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。

```cpp
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

函数的功能：给数组赋值，使其存储其索引值。（合法）

#### 习题6.33

> 编写一个递归函数，输出vector对象的内容。

#### 习题6.34

> 如果factorial 函数的停止条件如下所示，将发生什么？

```c++
if (val != 0)
```

如果val为正数，则无区别，若是val为负数，则会陷入无限递归。

#### 习题6.35

> 在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？

若是使用val--，递归函数一直传入的都是5，会陷入无限递归。

#### 习题6.36

> 编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名。

```c++
std::string (&func())[10];
```

#### 习题6.37

> 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？

```cpp
using string_arr = std::string[10];
string_arr &func();

auto func() -> std::string(&)[10];

std::string strarr[10];
decltype(strarr) &func();
```

尾置返回类型最好，代码很简洁且清晰明确。

#### 习题6.38

> 修改arrPtr函数，使其返回数组的引用。

```cpp
decltype(odd)& arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
```

#### 习题6.39

> > 说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
>
> ```cpp
> (a) int calc(int, int);
> 	int calc(const int, const int);
> (b) int get();
> 	double get();
> (c) int *reset(int *);
> 	double *reset(double *);
> ```

- (a)非法，值传递时会忽略顶层const，会报编译错误
- (b)非法，仅函数返回值不一致，不符合函数重载条件（返回double类型的值）
- (c)合法。第二条语句含义为：重置一个double类型指针。

#### 习题6.40

> > 下面的哪个声明是错误的？为什么？
>
> ```c++
> (a) int ff(int a, int b = 0, int c = 0);
> (b) char *init(int ht = 24, int wd, char bckgrnd);		
> ```

- (a)正确
- (b)错误，默认实参应放在形参列表的最后。

#### 习题6.41

> 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？

```c++
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14,'*');
```

- (a)非法，ht并未指定默认实参。
- (b)合法。
- (c)合法，但是与程序本意不符合。本意为`wd`使用默认实参，‘*’用于`bckgrnd`，实际上`wd`为字符对应的`ascii`值， `bckgrnd`为''。

#### 习题6.42

> 给make_plural函数的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。

#### 习题6.43

> 你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？

```c++
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

全部放进头文件中。（a）是内联函数，（b）是函数声明。

#### 习题6.44

> 将6.2.2节的isShorter函数改写成内联函数。

```c++
inline bool is_shorter(const string &lft, const string &rht) 
{
    return lft.size() < rht.size();
}
```

#### 习题6.45

> 回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。

#### 习题6.46

> 能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constxpre函数；如果不能，说明原因。

不能。constexpr函数的返回值类型及所有形参都得是字面值类型。

#### 习题6.47

> 改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。

#### 习题6.48

> > 说明下面这个循环的含义，它对assert的使用合理吗？
>
> ```c++
> string s;
> while (cin >> s && s != sought) { } //空函数体
> assert(cin);
> ```

不合理。推测应该是想判断`s`与`sought`的关系，应改为`assert(s != sought)`;

