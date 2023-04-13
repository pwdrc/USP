public class Personagem {
    private String nome;
    private String nomeVidaReal;
    private ArrayList<Superpoder> poderes;
    private int vida;

    public String getNome() {
        return this.nome;
    }

    public String getNomeVidaReal() {
        return this.nomeVidaReal;
    }

    public double getTotalPoder() {
        return this.poderes.size();
    }

    public int getVida() {
        return this.vida;
    }

    public void setNome(String pNome) {
        this.nome = pNome;
    }

    public void setNomeVidaReal(String pNomeVidaReal) {
        this.nomeVidaReal = pNomeVidaReal;
    }

    public void setVida(int pVida) {
        this.vida = pVida;
    }

    public void atacar(int intAtaque, String nomePoder, Personagem atacado) {
        
        if(this.poderes.contains(nomePoder)) {
            
            int chanceDeAcerto = (int) (Math.random() * 100);
            
            if(chanceDeAcerto > 50 && atacado.vida > 0) {
                atacado.vida -= intAtaque;
            }
        }
    }
}