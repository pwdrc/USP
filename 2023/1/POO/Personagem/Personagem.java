public class Personagem {
    private String nome;
    private String nomeVidaReal;
    private ArrayList poderes;

    public String getNome() {
        return this.nome;
    }

    public String getNomeVidaReal() {
        return this.nomeVidaReal;
    }

    public double getTotalPoder() {
        return this.poderes.size();
    }

    public void setNome(String pNome) {
        this.nome = pNome;
    }

    public void setNomeVidaReal(String pNomeVidaReal) {
        this.nomeVidaReal = pNomeVidaReal;
    }
}