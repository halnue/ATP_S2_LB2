# ATP_S2_LB2
## Контрольные вопросы
<details><summary>1. В чем заключается концепция наследования?</summary>
   Наследование - крайне переоцененый принцип ооп, позволяющий описать новый класс(дочерний) на основе уже существующего(родительского) с частично или полностью заимствующейся функциональностью. Данный механизм помогает избежать дублирования кода в случае, если нам нужно создать объект на основе уже существующего.
</details>
<details><summary>2.Чем отличается открытое, защищенное и закрытое наследование?</summary>
В с++ существует 3 типа наследования:
      
* Открытое(public): модификаторы доступа никак не изменяются в дочернем классе
* Защищённое(protected): публичные поля и методы становяться защищёнными в дочернем классе     
* Закрытое(private) : все поля и методы становяться приватными в дочернем классе

</details>
<details><summary>3.Какие преимущества и недостатки множественного наследования?</summary>

##### Преимущества:

* Это сокращает затраты на разработку класса и является формой повторного использования кода
##### Недостатки:

* Увеличивает сложность создания и модификации системы классов.
* Увеличивает связанность(coupling) классов.
##### Подведение итогов:
Использование множественного наследования следует избегать в большинстве случаев. Кроме множественного наследования абстрактного класса который имеет только чисто виртуальные функции(pure virtual functions). Данное наследование практически безопасным с точки зрения множественного наследования.
</details>
<details><summary>4. Для чего определяют виртуальный базовый класс?</summary>

1. Для определения класс, который не предполагает создаия конкретных объектов

1. Для решения проблемы общего предка у двух классов родителей
</details>
<details><summary>5. Для чего создают иерархии исключений?</summary>

Иерархия исключений нужна  для: 
1. Структурирования всех ошибок
1. Обработки всех наследников ошибки в одном блоке catch
</details>
<details><summary>6. В чем заключается концепция полиморфизма?</summary>

Полиморфизм - основной принцип ооп, позволяющий обращаться с классом наследника как с классом родителя.
</details>
<details><summary>7. Чем отличается полиморфизм времени компиляции от полиморфизма времени выполнения?</summary>

Полиморфизм времени компиляции(статический) происходит подбор параметров функций во время компиляции. Например шаблон(generic).
Полиморфизм времени выполнения(динамический) соответственно подбор происходит во время выполнения. Например виртуальные функции.
</details>
<details><summary>8. Что такое виртуальная функция?</summary>

Виртуальная функция(virtual function) - функция объявленная с ключевым словом virtual. При переопределении в производных классах во время выполнения выбирается, какую функцию вызвать.
</details>
<details><summary>9. Какие классы считаются полиморфными?</summary>

Полиморфный класс - класс который имеет хотя бы одну виртуальную функцию.
</details>
<details><summary>10. Почему в полиморфных классах целесообразно определять виртуальные деструкторы?</summary>

Деструкторы определяют виртуальными в полиморфных классах дабы избежать утечки памяти т. к. удаление производиться через указатель на базовый класс.
</details>
<details><summary>11. Что такое таблица виртуальных методов?</summary>

Таблица виртуальных методов - механизм для динамического связывания. 
Связывание - это сопоставление вызова функции с вызовом.
</details>
<details><summary>12. Что такое чисто виртуальная функция?</summary>

Чисто виртуальная функция(абстрактная функция, pure virtual function) - функция без реализации.
</details>
<details><summary>13. Что такое абстрактный класс?</summary>

Абстрактный класс - класс содержащий хотя бы одну абстрактную функцию.
</details>
<details><summary>14. Для чего используют шаблонные функции?</summary>

Шаблонные функции используются для лучшего переиспользования кода. То есть чтобы не создавать несколько одинаковых методов отличающихся только типом донных.
</details>
<details><summary>15. Можно шаблонную функцию отдельно реализовать для определенного типа?</summary>

Можно(Так как вопрос не понял несколько вариантов ответа)
Явная перегрузка функций-шаблонов:
```c++
template <class X> void swap(X &a, X &b)
{
X temp;
temp = a;
a = b;
b = temp;
}
// обобщенная версия swap()
void swap(int &af int &b)
{
int temp;
temp = a;
a = b;
b = temp;
cout << "Inside overloaded swap(int &, int &).\n";
}
```
или шаблон с возможность подстановки конкретнных типов:
```c++

template <typename T>
typename std::enable_if<std::is_same<T, int>::value || 
                        std::is_same<T, double>::value || 
                        std::is_same<T, float>::value>::type 

```
или шаблон с возможность подстановки наследников конкретнного класса:
```c++

template <
           typename T
         , typename = typename std::enable_if<std::is_base_of<Primitive, T>::value>::type
>
```
</details>
<details><summary>17. Как создать шаблон класса?</summary>

```c++
template <typename T>
class MyClass {}
```
</details>
<details><summary>18. Какими могут быть параметры шаблона?</summary>

Параметры могут быть типами данных, размером буфера или значением по умолчанию.
</details>
<details><summary>19. Для чего используют целые параметры шаблона?</summary>

Целое значение шаблонны может быть использовано например как раз размер массива или изначальное значение.
</details>
<details><summary>20. Что такое инстанцирование шаблона?</summary>

Инстанцирование шаблона - это создание конкретного типа из шаблона. 
</details>
<details><summary>21. Как осуществляется преобразование объектов инстанцийованих типов?</summary>

Также само как и для других классов. 
</details>
