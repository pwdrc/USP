public class SuperHeroi extends Personagem {
    
    public String getNomeVidaReal() {
        return super.getNomeVidaReal();
    }

    public double getTotalPoder() {
        return super.getTotalPoder();
    }

    public SuperHeroi(String Nome, String pNomeVidaReal) {
        super.setNome(Nome);
        super.setNomeVidaReal(pNomeVidaReal);
    }
}