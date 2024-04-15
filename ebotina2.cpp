#include <iostream>
/*
 окна для графических приложений, а у окон, как вы могли заметить,
 не всегда присутствует стандартный набор из трёх кнопок: «свернуть»,
 «развернуть» и «закрыть». Иногда разработчик оставляет только кнопку
 «закрыть» или не даёт возможности разворачивать окно на весь экран.
  У окна есть набор битовых флагов, отвечающих за наличие кнопок,
  панелей и прочих элементов. Создадим подобное упрощённое перечисление сами:
-------------------
Два последних условия будут выполнены.
Как включить опредёленный флаг у окна?
Нужно применить операцию ИЛИ к флагам, которые имеем, и к флагу, который нужно добавить:

currentWindowFlags = currentWindowFlags | HasMinButton;

Есть более быстрый способ:

 currentWindowFlags |= HasMinButton;

Теперь окно имеет кнопку «свернуть».
Для того, чтобы убрать какой-то из  флагов, надо постараться: сначала проинвертировать сам флаг, затем — его инверсию, а текущие флаги окна пропустить через операцию И:

CurrentWindowFlags = currentWindowFlags  & (~HasMinButton);   // или так:

currentWindowFlags &= (~HasMinButton);



Рассмотрим программу целиком:
*/
enum WindowStyle
{
    HasMaxButton = 1,
    HasMinButton = 2,
    HasCloseButton = 4
};

int main()
{
    // Создаём окно с кнопками «свернуть» и «закрыть»:
    int currentWindowFlags = HasMinButton | HasCloseButton;
    // 2 + 4 = 6, поэтому allButtons = 6;
    std::cout << "currentWindowFlags = " << 6 << "\n";
    // Если окно имеет кнопку «развернуть»:
    if (currentWindowFlags & HasMaxButton)
    {
        std::cout << "Fail" << std::endl;
    }
    // Если окно имеет кнопку «свернуть»:
    if (currentWindowFlags & HasMinButton)
    {
        std::cout << "Has min button" << std::endl;
    }
    // Если окно имеет кнопку «свернуть» и кнопку «закрыть»:
    if ((currentWindowFlags & HasMinButton) &&
        (currentWindowFlags & HasCloseButton))
    {
        std::cout << "Has min and close buttons" << std::endl;
    }
    // Убираем кнопку "свернуть":
    currentWindowFlags &= (~HasMinButton);
    if ((currentWindowFlags & HasMinButton) == false)
        std::cout << "No min button"
                  << "\n";
    return 0;
}
/*
Теперь кнопки «свернуть» у окна нет. В том месте, где была ответственная за флаг «свернуть» единица, теперь стоит ноль:

0 0 0 0 0 0 1 0  currentWindowFlags   (изначально у окна только эта кнопка)

0 0 0 0 0 0 1 0  HasMinButton

1 1 1 1 1 1 0 1  ~HasMinButton

0 0 0 0 0 0 0 0  currentWindowFlags & (~HasMinButto

------------------
Что будет выведено в результате выполнения такого кода?

  enum Buttons { Button1, Button2,Button3};
  int button = Button3 | Button2;
  std::cout << button;

  ответ - 3

*/