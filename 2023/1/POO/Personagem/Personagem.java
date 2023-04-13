import java.util.ArrayList;

public class Personagem {
    private String nome;
    private String nomeVidaReal;
    private ArrayList<Superpoder> poderes = new ArrayList<>();
    private int vida;

    public void setPoder(String pNome) {
        Superpoder poder = new Superpoder();
        this.poderes.add(poder);
    }

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
        
       
            
            int chanceDeAcerto = (int) (Math.random() * 100);
            
            if(chanceDeAcerto > 50) {
                atacado.setVida(atacado.getVida() - intAtaque);
            }
        
    }
}