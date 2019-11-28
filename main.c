#include <stdio.h>
#include <windows.h>

int is_light; //屏幕是否在亮
POINT  mouse_pst; //鼠标位置 结构体
long first_pst,second_pst,third_pst;  //连续三个鼠标 x y坐标的和

void checkScreen();  //检测屏幕
void turnOffScreen();  //关闭屏幕

int main() {
    PostMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,2);
    checkScreen();
}

//监视屏幕是否在亮
void checkScreen() {
    do{
        //TODO 检查屏幕是否在亮着 假如亮是1 不亮是2
        //is_light = thisIsCheckResult();
        //每两秒查一次
        Sleep(2000);
    }while(is_light == 2);
}

//关闭屏幕
void turnOffScreen(){
    //获取鼠标在屏幕中的x,y坐标
    GetCursorPos(&mouse_pst);
    first_pst = mouse_pst.x + mouse_pst.y;
    Sleep(1000);

    GetCursorPos(&mouse_pst);
    second_pst = mouse_pst.x + mouse_pst.y;
    Sleep(1000);

    GetCursorPos(&mouse_pst);
    third_pst = mouse_pst.x + mouse_pst.y;
    Sleep(1000);

    //取三次鼠标坐标 作为参考 鼠标不动就认为是闲置状态
    if(first_pst == second_pst && second_pst == third_pst){
        //关屏幕
        PostMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,2);
        //监测屏幕
        checkScreen();
    } else{
        exit(0);
    }
}