public class Automovel extends Veiculo {
    
    public void trocarOleo() {
        System.out.println("trocando óleo do automóvel");
    }

    @Override
    public void listarVerificacoes() {
        System.out.println("lista verificações do veiculo automóvel");
    }

    @Override
    public void ajustar() {
        System.out.println("ajusta automóvel");
    }

    @Override
    public void limpar() {
        SYstem.out.println("limpa automóvel");
    }
}