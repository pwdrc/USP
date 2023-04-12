public class Usuario {
    private String nome;
    private int idade;
    private String cpf;

    // construtor
    public Usuario(String nome, int idade, String cpf) {
        this.nome = nome;
        this.idade = idade;
        this.cpf = cpf;
    }

    // getters e setters
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setCPF(String cpf) {
        this.cpf = cpf;
    }

    public String getCFP() {
        return this.cpf;
    }

    @Override
    public String toString() {
        return "Usuario [nome=" + nome + ", idade=" + idade + ", cpfg=" + cpf + "]";
    }

}