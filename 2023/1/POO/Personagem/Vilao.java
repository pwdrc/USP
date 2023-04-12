public class Vilao extends Personagem {
    
    private int anosDePrisao;

    public int getAnosDePrisao() {
        return this.anosDePrisao;
    }

    public void setAnosDePrisao(int pAnosDePrisao) {
        this.anosDePrisao = pAnosDePrisao;
    }

    public Vilao(String Nome, String nomeVidaReal, ArrayList<String> poderes) {
        super(Nome, nomeVidaReal, poderes);
    }
}