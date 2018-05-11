/*DISEÑAR UN PROGRAMA DE CONTROL DE VENTAS QUE CUENTE CON LOS SIGUIENTES
REQUISITOS:

1.REGISTRO DE VENTAS DIARIAS
2.BUSCAR PRODUCTO
3.REALIZAR VENTA


CADA PRODUCTO DEBE TENER
NOMBRE **
PRECIO  **
EXITENCIAS   **
CODIGO DE BARRAS ***
LIMITE DE PIEZAS EN EXISTENCIA***

MENU
0.INICIAR SESION COMO ADMINISTRADOR O VENDEDOR (INGRESANDO EL NOMBRE DEL VENDEDOR)
1.REALIZAR VENTA
2.AGREGAR PRODUCTO  (CONTROL DE ADMINISTRADOR)
3.ELIMINAR PRODUCTO  (CONTROL DE ADMINITRADOR)
4.BUSCAR PRODUCTO y venderlo en todo caso
5.MOSTRAR PRODUCTOS AGOTADOS
6.Modificar Productos (precio,nombre,codigo,limit) ADMINISTRADOR
7.Regresar a ventana anterior (tecla esc o boton return)
*/



#include<iostream>
#include<string>
using namespace std;


class Product{
public:
    Product();
    Product(string n,string c,float p,unsigned e,unsigned l);
    void show_details();//READY
    void set_Price(float p);//READY
    void set_Name(string n);//READY
    void set_Bar_Code(string b);//READY
    void set_Limit(unsigned int l);//READY
    void set_Exist(unsigned int e);//READY
    string get_name();//READY
    string get_code();//READY
    float get_price();//READY
    float get_limit();//READY
    float get_Exist();//READY
    void erase_Product();//READY

private:
    float price;
    string name,bar_code;
    unsigned int limit,exist;
};

void Product::erase_Product(){  //METODO DE LA CLASE "PRODUCT" QUE ELIMINA TODA LA INFORMACIÓN DE DICHO PRODUCTO
    price=0;
    name="Sin Nombre";
    bar_code="Sin Codigo";
    limit=0;
    exist=0;

}

float Product::get_Exist(){
    return exist;
}

float Product::get_limit(){
    return limit;
}

float Product::get_price(){
    return price;
}

string Product::get_name(){
    return name;
}

string Product::get_code(){
    return bar_code;
}


void Product::set_Exist(unsigned int e){
    exist=e;
}

void Product::set_Limit(unsigned l){
    limit=l;
}

void Product::set_Name(string n){
    name=n;
}

void Product::set_Bar_Code(string b){
    bar_code=b;
}

void Product::set_Price(float p){
    price=p;
}


Product::Product(){
    price=0;
    name="Sin Nombre";
    bar_code="Sin Codigo";
    limit=0;
    exist=0;
}

Product::Product(string n,string c,float p,unsigned e,unsigned l){
    price=p;
    name=n;
    bar_code=c;
    exist=e;
    limit=l;
}





void Product::show_details(){   //METODO QUE SOLAMENTE MUESTRA LOS DETALLES DEL OBJETO SELECCIONADO
    cout<<"Nombre:"<<name<<endl;
    cout<<"Precio:"<<price<<endl;
    cout<<"Codigo:"<<bar_code<<endl;
    cout<<"Limite de Piezas:"<<limit<<endl;
    cout<<"Cantidad de Piezas Existentes:"<<exist<<endl;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////FUNCION MAIN//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///VARABLES GLOBALES\\\

#define MAX 1000
int unsigned MAXN=0;   ///LA PRIMERA POSICIÓN DISPONIBLE DONDE SE PUEDE AGREGAR UN OBJETO
Product nuevo[MAX];    ///VECTOR DE TAMAÑO MAX QUE ES DONDE SE GUARDARÁ LA INFORMACIÓN


///PROTOTYPES\\\

void menu();   //FUNCION QUE HACE EL BUCLE PARA QUE EL USUARIO LA USE
void Add_Product();  //FUNCION PARA AGRAGAR UN NUEVO PRODUCTO
void Delete_Product();  //FUNCION PARA ELIMINAR EL PRODUCTO TIENE QUE VOLVER A ACOMODAR LOS OBJETOS
void Find_Product();    //FUNCION PARA BUSCAR UN PRODUCTO
void change_last(int i);
void show_vector();
void edit_Product();

int main(){
    menu();
    return 0;
}


void menu(){
    unsigned int x;
    do{
        cout<<"Que desea realizar?"<<endl<<"[1]Agregar Producto"<<endl<<"[2]Eliminar Producto"<<endl<<"[3] Buscar Producto Por Codigo"<<endl<<"[4] Editar Producto"<<endl<<"[5] Mostrar toda la lista de productos"<<endl;
        cin>>x;
        switch (x){
        case 1:
            Add_Product();
            break;
        case 2:
            Delete_Product();
            break;
        case 3:
            Find_Product();
            break;
        case 4:
            edit_Product();
            break;
        case 5:
            show_vector();
            break;
        //default:
          //  return;
        }
    }while(   1<=x<=5    );
}

void Add_Product(){
    unsigned int d=0,l=0,e=0;
    float p=0;
    string b, n;
    do{
    cout<<"Ingrese el nombre del producto"<<endl;
    cin.ignore();
    getline(cin,n);
    cout<<"Ingrese el precio del producto"<<endl;
    cin>>p;
    cout<<"Ingrese el codigo de barras del Producto"<<endl;
    cin.ignore();
    getline(cin,b,'\n');
    cout<<"Ingrese el limite minimo de productos existentes"<<endl;
    cin>>l;
    cout<<"Ingrese las existencias del Producto"<<endl;
    cin>>e;
    cout<<"Quieres agregar otro Producto?   [1]SI [0]NO"<<endl;
    cin>>d;

    nuevo[MAXN].set_Price(p);
    nuevo[MAXN].set_Name(n);
    nuevo[MAXN].set_Bar_Code(b);
    nuevo[MAXN].set_Limit(l);
    nuevo[MAXN].set_Exist(e);
    MAXN++;

    }while(d==1);
}

void Delete_Product(){
    unsigned int d,i=0;
    string n;
    cout<<"Como quiere buscar el producto a ingresar?   [1]Por Nombre   [2]Por Codigo de Barras"<<endl;
    cin>>d;
    if(d==1){
        cout<<"Ingresa el Nombre del Proucto que deseas eliminar"<<endl;
        cin.ignore();
        getline(cin,n,'\n');
        ///buscando el producto que se quiere eliminar
        while(nuevo[i].get_name()!="Sin Nombre"    ){
                if(nuevo[i].get_name()==n){
                    cout<<"PRODUCTO EN LA POSICION i:"<<i<<endl;
                    change_last(i);
                    nuevo[MAXN-1].erase_Product();
                    cout<<"Producto eliminado"<<endl;
                    MAXN--;
                    }
                    i++;
        }
        if(nuevo[i].get_name()=="Sin Nombre"){
            cout<<"No encontrado por nombre"<<endl;
            return;
        }
    }

    if(d==2){
        cout<<"Ingresa el Codigo del Proucto que deseas eliminar"<<endl;
        cin.ignore();
        getline(cin,n,'\n');
        ///buscando el producto que se quiere eliminar
        while(nuevo[i].get_code()!="Sin Codigo"    ){
                if(nuevo[i].get_code()==n){
                    cout<<"PRODUCTO EN LA POSICION i:"<<i<<endl;
                    change_last(i);
                    nuevo[MAXN-1].erase_Product();
                    cout<<"Producto eliminado"<<endl;
                    MAXN--;
                    }
                    i++;
        }
        if(nuevo[i].get_code()=="Sin Codigo"){
            cout<<"No encontrado por codigo"<<endl;
            return;
        }
    }



}


void Find_Product(){
    int i=0;
    float p=0;
    string c;
    cout<<"Ingrese el codigo de Producto que desea Buscar"<<endl;
    cin>>c;
    while(nuevo[i].get_code()!=c){
        i++;
    }
    nuevo[i].show_details();
}


void change_last(int i){

    nuevo[i].set_Bar_Code(nuevo[MAXN-1].get_code());
    nuevo[i].set_Exist(nuevo[MAXN-1].get_Exist());
    nuevo[i].set_Limit(nuevo[MAXN-1].get_limit());
    nuevo[i].set_Name(nuevo[MAXN-1].get_name());
    nuevo[i].set_Price(nuevo[MAXN-1].get_price());
}

void show_vector(){
    unsigned int i=0;
    while(nuevo[i].get_name()!="Sin Nombre"){
        nuevo[i].show_details();
        cout<<endl<<endl;
        i++;
    }
}


void edit_Product(){
    string c,b;
    int i=0,d=0;
    float p;
    unsigned u=0;
    cout<<"Ingrese el codígo de barras del Producto que desea editar"<<endl;
    cin>>c;

    for(int i=0;nuevo[i].get_code()!=c;i++){
        if(nuevo[i].get_code()=="Sin Codigo"){
            cout<<"Producto no Encontrado"<<endl;
            return;
        }
    }

    cout<<"Que deseas Modificar?"<<endl;
    cout<<"[1]Nombre [2]Codigo de barras [3]Precio [4]Existencias [5]Limite de existencias";
    cin>>d;
    switch(d){
    case 1:
        cout<<"Ingresa el nuevo nombre"<<endl; cin>>b;
        nuevo[i].set_Name(b);
        break;
    case 2:
        cout<<"Ingresa el nuevo Codigo de Barras"<<endl; cin>>b;
        nuevo[i].set_Bar_Code(b);
        break;
    case 3:
        cout<<"Ingresa el Nuevo Precio"<<endl; cin>>p;
        nuevo[i].set_Price(p);
        break;
    case 4:
        cout<<"Ingrese las nuevas existencias"<<endl; cin>>u;
        nuevo[i].set_Exist(u);
        break;
    case 5:
        cout<<"Ingrese el nuevo limite de existencias"<<endl; cin>>u;
        nuevo[i].set_Limit(u);
        break;
    }
}
