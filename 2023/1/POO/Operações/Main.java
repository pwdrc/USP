public class Main {
    public static void main(String[] args) {
        
        Usuario u1 = new Usuario("Pedro", 26, "1111111");
        Operacao o1 = new Operacao();
        o1.realizar_calculo();
        Resultado r1 = new Resultado(u1, o1);

        System.out.println(r1.getUsuario().getNome());
        System.out.println(o1.getOpName());
        System.out.println(r1.getData());
    }
}