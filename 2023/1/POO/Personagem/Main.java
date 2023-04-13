public class Main {
    public static void main(String[] args) {
        
        SuperHeroi banana = new SuperHeroi("Homem-Banana", "Lucio Bananeira");
        banana.setVida(98);
        banana.setPoder("banana-split");
                
        Vilao bergamota = new Vilao("Homem-Bergamota", "Ricardo Bergman");
        bergamota.setVida(103);
        bergamota.setPoder("suco-azedo");


        while(banana.getVida() > 0 && bergamota.getVida() > 0) {
            int primeiroAtaque = (int) (Math.random() * 10) + 1;

            if(primeiroAtaque <= 5) {
                banana.atacar(10, "banana-split", bergamota);
            } else {
                bergamota.atacar(11, "suco-azedo", banana);
            }

            System.out.println("Vida do homem-banana: " + banana.getVida());
            System.out.println("Vida do homem-bergamota: " + bergamota.getVida());
        }
    }
}