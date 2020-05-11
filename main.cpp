/* Includes */
#include "mbed.h"
#include "XNucleoIKS01A2.h"

/* Instantiate the expansion board */
static XNucleoIKS01A2 *mems_expansion_board = XNucleoIKS01A2::instance(D14, D15, D4, D5);
Serial serialCom(SERIAL_TX, SERIAL_RX);


/* Retrieve the composing elements of the expansion board *///
static LSM303AGRAccSensor *accelerometer = mems_expansion_board->accelerometer;

DigitalIn mybutton(USER_BUTTON);


/* Simple main function */
int main() 
{
  
    uint8_t id;
    int32_t axes[3];
    float x,y;

    accelerometer->enable();
    accelerometer->read_id(&id);
 
    while(1) {
    
        accelerometer->get_x_axes(axes);
   
   
        x=axes[0];
        y=axes[1];
    
        //    if(x>300&&y>350)
        //    {
        //      //up-right=5
        //      serialCom.printf("5");  
        //    }
        //    else if(x>300&&y<-350)
        //    {
        //        //up-left=6
        //        serialCom.printf("6");  
        //    }
        //    else if(x<-300&&y>350)
        //    {
        //        //down-right=7
        //        serialCom.printf("7");  
        //    }
        //    else if(x<-300&&y<-350)
        //    {
        //        //down-left=8
        //        serialCom.printf("8");  
        //    }
        if(x>500)
        {
            //up=1
            serialCom.printf("1");  
            wait(0.4);
        }
        else if(x<-500)
        {
            //down=2
            serialCom.printf("2");  
            wait(0.4);
        }
        else if(y<-550)
        {
            //right=3
            serialCom.printf("3");  
            wait(0.4);
        }
        else if(y>550)
        {
            //left=4
            serialCom.printf("4");  
            wait(0.4);
        }
        else
        {
            //idle=0
            serialCom.printf("0");
        }
        if (mybutton == 0) { // Button is pressed
          serialCom.printf("9");
        }
        
        wait(0.05);
        fflush(stdout);
    }
}
