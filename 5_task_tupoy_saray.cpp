#include <iostream>
#include <vector>



float colorTemp(int time)

{

    if ((time >= 0 && time <= 16) || (time >= 24 && time <= 40))   return 5000;
    else if ((time > 20 && time < 24) || (time > 44 && time < 48)) return 2700;
    else if ((time > 16 && time <= 20) || (time > 40 && time <= 44))
      {
        if ((time == 17 || time == 41))  return (5000 - (2300 * 25 / 100));
        if ((time == 18 || time == 42))  return (5000 - (2300 * 50 / 100));
        if ((time == 19 || time == 43))  return (5000 - (2300 * 75 / 100));
        if ((time == 20 || time == 44))  return (5000 - (2300 * 100 / 100));
      } 
return 5000;

}


bool timeToOutsideLigth(int i)
{
   if ((i < 5) || ((i >= 16) && (i < 29)) || ((i>= 29) && (i<= 48))) return true;
   else return false;
}
enum class switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
void print(int decimal)

{

    std::vector<int> vec(0);
    int result;
    do
    {
        result = decimal % 2;
        vec.push_back(result);
        decimal = decimal / 2;
    } while (decimal > 0);

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}
int main()
{
    int tempInside, tempOutside;
    std::string movement, light;
    int switcMap = 0;
    for (int i = 0; i < 48; ++i)
    {
        std::cout << "Time: " << i << ":00\n";
        print(switcMap);
        std::cout << "Enter the temperature inside, temperature outside, is there movement outside (yes/no), and state of homelight (on/off): " << "\n";
        std::cin >> tempInside >> tempOutside >> movement >> light;
        
        /////////////////////Outside Temperature/////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////        
        if (tempOutside < 0 )
        {
            if (!(switcMap & static_cast<int>(switches::WATER_PIPE_HEATING)))
                {
                    switcMap |= static_cast<int>(switches::WATER_PIPE_HEATING);
                    std::cout << "Water pipe heating is on\n";
                }
        }

        if (tempOutside > 5)
        {
            if (switcMap & static_cast<int>(switches::WATER_PIPE_HEATING))
            {
                switcMap &= ~static_cast<int>(switches::WATER_PIPE_HEATING);
                std::cout << "Water pipe heating is off\n";
            }
        }
//////////////////////Outside Lights/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
        if ((timeToOutsideLigth(i)) && (movement == "yes") && !(switcMap & static_cast<int> (switches::LIGHTS_OUTSIDE)))
        {
            switcMap |= static_cast<int> (switches::LIGHTS_OUTSIDE);
            std::cout << "Lights outside are on" << std::endl;
        }
        else if (((!timeToOutsideLigth(i) || movement == "no" )) && (switcMap & static_cast<int>(switches::LIGHTS_OUTSIDE)))
            {
                switcMap &= ~static_cast<int>(switches::LIGHTS_OUTSIDE);
                std::cout << "Lights outside are off\n";
            }
/////////////////////Inside Heaters/////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////       
        if (tempInside < 22 && !(switcMap & static_cast<int> (switches::HEATERS)))
        {
            switcMap |= static_cast<int> (switches::HEATERS);
            std::cout << "Heaters are on\n";
        }
        else if (tempInside > 25 && (switcMap & static_cast<int>(switches::HEATERS)))
        {
            switcMap &= ~static_cast<int> (switches::HEATERS);
            std::cout << "Heaters are off\n";
        }
//////////////////Conditioner////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////   
        if (tempInside >= 30 && !(switcMap & static_cast<int> (switches::CONDITIONER)))
        {
            switcMap |= static_cast<int> (switches::CONDITIONER);
            std::cout << "Conditioner is on\n";
        }
        else if (tempInside <= 25 && (switcMap & static_cast<int>(switches::CONDITIONER)))
        {
            switcMap &= ~static_cast<int> (switches::CONDITIONER);
            std::cout << "Conditioner is off\n";
        }
/////////////////Inside Lights////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////        
        
        if (light == "on" && !(switcMap & static_cast<int> (switches::LIGHTS_INSIDE)))
        {
            switcMap |= static_cast<int> (switches::LIGHTS_INSIDE);
            std::cout << "Lights inside are on\n";
        }
        else if (light == "off" && (switcMap & static_cast<int>(switches::LIGHTS_INSIDE)))
        {
            switcMap &= ~static_cast<int> (switches::LIGHTS_INSIDE);
            std::cout << "Lights inside are off\n";
        }
////////////////Color Temperature///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

        if ((switcMap & static_cast<int>(switches::LIGHTS_INSIDE)))
        {
            std::cout << "Color temperature: " << colorTemp(i) << "\n";
            //std::cout << "Color temperature: " << colorTemp(i) << "\n";
        } 


              
       
    }
}