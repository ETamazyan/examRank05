#include "vect2.hpp"
#include <iostream>

int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2; // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
   std::cout << v4++ << std::endl; // 2, 3
    std::cout << ++v4 << std::endl; // 3, 4
    std::cout << v4-- << std::endl; // 2, 3
    std::cout << --v4 << std::endl; // 1, 2
   v2 += v3; // 2, 4
    v1 -= v2; // -2, -4
    v2 = v3 + v3 *2; // 3, 6
    v2 = 3 * v2; // 9, 18
    v2 += v2 += v3; // 20, 40
    v1 *= 42; // -84, -168
    v1 = v1 - v1 +v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}



/*
Լավ, եկ՛ սա բացատրեմ **հստակ, քայլ առ քայլ և քննության համար հիշվող ձևով**, ամբողջությամբ **հայերենով** 🙂
Նպատակը այն է, որ դու կարողանաս **ինքնուրույն գրել այս կոդը**, ոչ թե պարզապես copy–paste անել։

---

## 🔹 Առաջադրանքի գաղափարը (ինչ են քեզանից ուզում)

Դու պետք է ստեղծես **C++ class**, որը ներկայացնում է **երկչափ մաթեմատիկական վեկտոր**.

Վեկտորը ունի **2 ամբողջ թիվ (int)**՝

* x
* y

Օրինակ՝
`vect2(1, 2)` → `{1, 2}`

---

## 🔹 Ֆայլերի կառուցվածք

Քեզ պետք են **2 ֆայլ**.

1. `vect2.hpp` → **դասի հայտարարում (interface)**
2. `vect2.cpp` → **դասի իրականացում (implementation)**

👉 Սա դասական C++ մոտեցում է, և քննության ժամանակ շատ կարևոր է։

---

## 🔹 vect2 class-ի կառուցվածքը

### 🔸 Private մաս

```cpp
private:
    int x;
    int y;
```

🔹 **Ինչու private?**
Որ դրսից **ուղղակիորեն չկարողանան փոխել** x և y արժեքները։
Մուտքը արվում է միայն օպերատորների միջոցով (`[]`, `+`, `+=`, և այլն)։

---

### 🔸 Public մաս (ինչ կարող է օգտագործողը անել)

Այստեղ են բոլոր կոնստրուկտորները և օպերատորները։

---

## 🔹 Կոնստրուկտորներ (Constructors)

### 1️⃣ Default constructor

```cpp
vect2::vect2(): x(0), y(0) {}
```

📌 Եթե գրենք՝

```cpp
vect2 v;
```

ապա
➡️ `v = {0, 0}`

---

### 2️⃣ Կոնստրուկտոր երկու թվով

```cpp
vect2::vect2(int num1, int num2): x(num1), y(num2) {}
```

📌

```cpp
vect2 v(3, 4); // {3, 4}
```

---

### 3️⃣ Copy constructor

```cpp
vect2::vect2(const vect2& other): x(other.x), y(other.y) {}
```

📌 Օգտագործվում է, երբ գրում ենք՝

```cpp
vect2 v2(v1);
```

➡️ v2-ը ստանում է v1-ի արժեքները։

---

### 4️⃣ Assignment operator =

```cpp
vect2& vect2::operator=(const vect2& other)
```

📌 Օգտագործվում է, երբ գրում ենք՝

```cpp
v2 = v1;
```

🔹 Ստուգում ենք `this != &other`, որ ինքն իրեն չկրկնօրինակենք։

---

## 🔹 [] օպերատոր (access vector components)

### Ոչ const տարբերակ

```cpp
int& vect2::operator[](int index)
```

📌 Թույլ է տալիս գրել՝

```cpp
v[0] = 10;
v[1] = 20;
```

🔹 index = 0 → x
🔹 index = 1 → y

---

### const տարբերակ

```cpp
int vect2::operator[](int index) const
```

📌 Օգտագործվում է, երբ օբյեկտը `const` է՝

```cpp
const vect2 v;
std::cout << v[0];
```

⚠️ Չի կարելի վերադարձնել reference (`int&`), քանի որ const է։

---

## 🔹 Տպում << օպերատոր

```cpp
std::ostream& operator<<(std::ostream& os, const vect2& other)
```

📌 Թույլ է տալիս գրել՝

```cpp
std::cout << v;
```

Եվ ստանալ՝

```
{1, 2}
```

---

## 🔹 ++ և -- օպերատորներ

### Prefix (++v)

```cpp
vect2& vect2::operator++()
```

📌 Նախ ավելացնում է, հետո վերադարձնում։

---

### Postfix (v++)

```cpp
vect2 vect2::operator++(int)
```

📌

1. Պահում է հին արժեքը
2. Ավելացնում է
3. Վերադարձնում է **հին արժեքը**

🔹 Նույն տրամաբանությամբ է `--`-ը։

---

## 🔹 Մաթեմատիկական օպերատորներ

### ➕ Գումարում

```cpp
vect2 vect2::operator+(const vect2& other) const
```

📌

```
{1,2} + {3,4} = {4,6}
```

---

### ➖ Հանում

```cpp
vect2 vect2::operator-(const vect2& other) const
```

---

### ✖️ Վեկտոր × վեկտոր

```cpp
vect2 vect2::operator*(const vect2& other) const
```

📌

```
{2,3} * {4,5} = {8,15}
```

---

### ✖️ Վեկտոր × թիվ

```cpp
vect2 vect2::operator*(int num) const
```

📌

```
{2,2} * 3 = {6,6}
```

---

### ✖️ Թիվ × վեկտոր

```cpp
vect2 operator*(int num, const vect2& other)
```

📌 Սա **պետք է լինի class-ից դուրս**, որովհետև ձախ կողմում թիվ է։

---

## 🔹 +=, -=, *= օպերատորներ

Օրինակ՝

```cpp
vect2& vect2::operator+=(const vect2& other)
```

📌 Փոխում է հենց օբյեկտը

```cpp
v1 += v2;
```

---

## 🔹 Unary minus (-v)

```cpp
vect2 vect2::operator-() const
```

📌

```
{2, -3} → {-2, 3}
```

---

## 🔹 Համեմատություն == և !=

```cpp
bool vect2::operator==(const vect2& other)
```

📌 Վերադարձնում է true, եթե x և y հավասար են։

```cpp
bool vect2::operator!=(const vect2& other)
```

📌 Պարզապես հակառակն է `==`-ի։

---

## 🔹 Ինչ պետք է հիշես քննության համար ⭐

Եթե սա հիշես, **կկարողանաս գրել ամբողջ class-ը**.

1️⃣ Class = տվյալներ + օպերատորներ
2️⃣ `hpp` → հայտարարում
3️⃣ `cpp` → իրականացում
4️⃣ `[]` → reference + const տարբերակ
5️⃣ `<<` → friend / global function
6️⃣ Prefix vs Postfix (`int` dummy parameter)
7️⃣ Թիվ × վեկտոր → class-ից դուրս

---

Եթե ուզես, հաջորդ քայլով կարող եմ՝

* տալ **մեմոնիկ սխեմա** (ինչ հերթականությամբ գրել քննության ժամանակ)
* կամ **քեզ տալ դատարկ template**, որ փորձես ինքդ գրել 💪

*/