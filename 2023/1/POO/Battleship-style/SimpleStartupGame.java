class SimpleStartupGame {
    public static void main(String[] args) {
        int numOfGuesses = 0;
        
        SimpleStartup game = new SimpleStartup();
        
        int ramdomNum = (int) (Math.random() * 5);
        int[] locations = {ramdomNum, ramdomNum + 1, ramdomNum + 2};
        game.setLocationCells(locations);
        GameHelper helper = new GameHelper();
        boolean isAlive = true;
        while(isAlive) {
            int guess = helper.getUserInput("enter a number: ");
            String result = game.checkYourself(guess);
            numOfGuesses++;
            if(result.equals("kill")) {
                isAlive = false;
                System.out.println("You took " + numOfGuesses + " guesses");
            }
        }
    }
}