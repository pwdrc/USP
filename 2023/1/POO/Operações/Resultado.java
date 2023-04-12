import java.time.LocalDate;

public class Resultado {
    private Usuario usuario;
    private Operacao operacao;
    private LocalDate data = LocalDate.now();

    public Resultado(Usuario usuario, Operacao operacao) {
        this.usuario = usuario;
        this.operacao = operacao;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public Operacao getOperacao() {
        return operacao;
    }

    public LocalDate getData() {
        return data;
    }
}