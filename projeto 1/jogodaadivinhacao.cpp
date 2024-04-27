 #include<iostream>
 #include<cstdlib>
 #include<ctime>
 using namespace std;

int main () {
    cout << "===================================" << endl ;
    cout << "* Bem-Vindo ao game da adivinhacao*" << endl ;
    cout << " * tente um numero entre 1 e 100 *" << endl ;
    cout << "===================================" << endl ;

    cout << "escolha o seu nivel de dificuldade" << endl;
    cout << "Facil(F) , Medio (M) , Dificil (D)" << endl;

    char dificuldade ;
    cin >> dificuldade ;

    srand (time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int numero_de_tentativas;

    if(dificuldade == 'f' ) {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'm'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }   

    bool nao_acertou = true ;
    int tentativas = 0;

    double pontos;

    if (numero_de_tentativas == 15){
        pontos = 500.0;
    }
    else if(numero_de_tentativas == 10){
        pontos = 750.0;
    }
    else {
        pontos = 1000.0;
    }
    

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
        cout.precision(2);
        cout << fixed ;
        cout << "qual o seu chute ? " << endl;
        int chute;
        cin >> chute;

        double multiplicador;

        if (numero_de_tentativas == 15){
            multiplicador = 0.73;
        }
        else if(numero_de_tentativas == 10){
            multiplicador = 1.18;
        }
        else {
            multiplicador = 1.67;
        }

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)*multiplicador;
        pontos = pontos - pontos_perdidos;

        cout << "" << endl;
        cout << "================================================" << endl;
        cout << "tentativa de numero :" << tentativas << endl ;
        cout << "o valor do seu chute e: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        int atencao = numero_de_tentativas - 1;

        if(acertou) {
            nao_acertou = false ;
            break;
        }
        else if (maior) {
            cout << "================================================" << endl;
            cout << "que pena voce errou , seu chute foi maior , tente um numero menor" << endl;
            cout << "voce perdeu ja perdeu :" << pontos_perdidos << " pontos" << endl ;
            cout << "================================================" << endl;           
        }
        else {
            cout << "================================================" << endl;            
            cout << "meu deus , seu chute passou perto , tente um numero maior agora" << endl;
            cout << "voce perdeu ja perdeu :" << pontos_perdidos << " pontos" << endl ;
            cout << "================================================" << endl;
        }

        if (tentativas == atencao){
            cout << "" << endl;
            cout << "***********************************************************" << endl;
            cout << "ATENCAO , suas tentativas serao zeradas caso erre novamente" << endl;
            cout << "***********************************************************" << endl;
        }
    };
    if (nao_acertou == true){
        pontos = 0;
        cout << "================================================" << endl;
        cout << "total de tentativas : " << tentativas << endl ;
        cout << "que pena , voce errou o numero secreto !" << endl ;
        cout << "Sua pontuacao atual e de :"<<pontos<< " pontos" <<endl;
        cout << "================================================" << endl;  
    }
    else {
        cout << "================================================" << endl;
        cout << "" << endl;
        cout << "================================================" << endl;
        cout << "total de tentativas : " << tentativas<< endl ;
        cout << "parabens !! voce acertou o numero secreto" << endl ;
        cout << "Sua pontuacao foi de :"<<pontos<< " pontos" <<endl;
        cout << "================================================" << endl;  
    }    
}

