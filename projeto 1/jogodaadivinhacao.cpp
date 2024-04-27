 #include<iostream>
 using namespace std;

int main () {
    cout << "=====================" << endl ;
    cout << "* Bem-Vindo ao game *" << endl ;
    cout << "=====================" << endl ;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true ;
    int tentativas = 0;

    double pontos = 1000.0;

    while ( nao_acertou ) {
        cout << "qual o seu chute ? " << endl;
        int chute;
        cin >> chute;
        tentativas++;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)*2.0;
        pontos = pontos - pontos_perdidos;

        cout << "o valor do seu chute e: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou) {
            cout << "================================================" << endl;
            cout << "total de tentativas : " << tentativas << endl ;
            cout << "parabens !! voce acertou o numero secreto" << endl ;
            cout << "Sua pontuacao foi de :"<<pontos<< "pontos" <<endl;
            cout << "================================================" << endl;
            nao_acertou = false ;
        }
        else if (maior) {
            cout << "seu numero de tentativas e :" << tentativas << endl ;
            cout << "que pena voce errou , seu chute foi maior , tente um numero menor" << endl;
            cout << "voce perdeu ja perdeu :" << pontos_perdidos << "pontos" << endl ;
            cout << "" << endl;
        }
        else {
            cout << "seu numero de tentativas e :" << tentativas << endl ;
            cout << "meu deus , seu chute passou perto , tente um numero maior agora" << endl;
            cout << "voce perdeu ja perdeu :" << pontos_perdidos << "pontos" << endl ;
            cout << "" << endl;
        }
    };  
}

