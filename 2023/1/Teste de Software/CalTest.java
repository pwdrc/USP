import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class CalTest {

    private Cal c;

    @BeforeEach
    public void setUp() throws Exception {
        c = new Cal();
        //outputStream = new ByteArrayOutputStream();
        //originalOut = System.out;
        //System.setOut(new PrintStream(outputStream));
    }

    @Test
    void testMain() {
        //PrintStream customOut = new PrintStream(outputStream);
        //System.setOut(customOut);
        String[] args;
        
        args = new String[]{};
        c.main(args);

        args = new String[]{"1", "2023"};
        c.main(args);
        
        args = new String[]{"5"};
        c.main(args);
        
        args = new String[]{"2023"};
        c.main(args);
        
        args = new String[]{"0"};
        c.main(args);
        
        args = new String[]{"13"};
        c.main(args);
        
        args = new String[]{"abc"};
        c.main(args);
        
        args = new String[]{"1", "2", "3"};
        c.main(args);
        
        args = new String[]{"1", "200000"};
        c.main(args);
        
        args = new String[]{"-1", "2023"};
        c.main(args);
        
        final String[] argsInvalid1 = {"abc", "2023"};
        assertDoesNotThrow(() -> c.main(argsInvalid1));
        
        final String[] argsInvalid2 = {"13", "2023"};
        assertDoesNotThrow(() -> c.main(argsInvalid2));
        
        final String[] argsInvalid3 = {"12", "abc"};
        assertDoesNotThrow(() -> c.main(argsInvalid3));
    }
    

    @Test
    void testFirstOfMonth() {
    	// Teste para um ano não bissexto
        assertEquals(0, c.firstOfMonth(1, 2023)); // Janeiro de 2023 começa em um domingo
        assertEquals(3, c.firstOfMonth(5, 2023)); // Maio de 2023 começa em uma quarta-feira
        assertEquals(6, c.firstOfMonth(12, 2023)); // Dezembro de 2023 começa em um sábado
        
        // Teste para um ano bissexto
        assertEquals(6, c.firstOfMonth(1, 2024)); // Janeiro de 2024 começa em um sábado
        assertEquals(2, c.firstOfMonth(2, 2024)); // Fevereiro de 2024 começa em uma terça-feira
        assertEquals(0, c.firstOfMonth(12, 2024)); // Dezembro de 2024 começa em um domingo
    }

	@Test
	void testNumberOfDays() {
		int result = c.numberOfDays(2, 2024);
		assertEquals(29, result);
		
		result = c.numberOfDays(9, 1752);
		assertEquals(19, result);
	}

	@Test
	void testIsLeap() {
	    // Test case 1: Leap year divisible by 400
	    boolean result = c.isLeap(2000);
	    assertTrue(result);
	    
	    result = c.isLeap(400);
	    assertTrue(result);
	    
	    result = c.isLeap(401);
	    assertFalse(result);

	    // Test case 2: Leap year divisible by 4 but not by 100
	    result = c.isLeap(2024);
	    assertTrue(result);

	    // Test case 3: Not a leap year divisible by 100
	    result = c.isLeap(1900);
	    assertFalse(result);

	    // Test case 4: Not a leap year not divisible by 4
	    result = c.isLeap(2019);
	    assertFalse(result);
	}
	
	@Test
	void testCal() {
		String result = c.cal(1, 19);
		assertEquals("       1  2 14 15 16\n17 18 19 20 21 22 23\n24 25 26 27 28 29 30", result);
		
	}


}
