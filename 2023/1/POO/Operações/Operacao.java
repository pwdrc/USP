import java.util.Scanner;

public class Operacao {

    private String opNome;
    private Float r;

    // getter 
    public String getOpName() {
        return this.opNome;
    }

    public Float getResultado(){
        return this.r;
    }
    public float realizar_calculo() {

        Scanner scanner = new Scanner(System.in);


        int op = scanner.nextInt();

        float[] num = new float[2];
        for(int i = 0; i < 2; i++) {
            num[i] = scanner.nextFloat();
        }

        switch(op) {
            // soma
            case 1:
                this.opNome = "soma";
                this.r = num[0] + num[1];
                break;
            // subtração
            case 2:
                this.opNome = "subtração";
                this.r = num[0] - num[1];
                break;
            // produto
            case 3:
                this.opNome = "multiplicação";
                this.r = num[0] * num[1];
                break;
            // coeficiente
            case 4:
                this.opNome = "divisão";
                this.r = num[0] + num[1];
                break;
        }
    
        return this.r;
    }
}