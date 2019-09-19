

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   { 
	   
	   System.out.println("Scheme Test\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - www.google.com");
		   assertTrue(urlVal.isValid("www.google.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - ftp://www.google.com");
		   assertTrue(urlVal.isValid("ftp://www.google.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com");
		   assertTrue(urlVal.isValid("http://www.google.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Fail
	   try {
		   System.out.println("Testing - htt://www.google.com");
		   assertTrue(urlVal.isValid("htt://www.google.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   System.out.println("\n****************************");
   }
   
   public void testYourSecondPartition()
   {
   
	   System.out.println("Authority Test\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://google.com");
		   assertTrue(urlVal.isValid("http://google.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.0.0.0.0.com");
		   assertTrue(urlVal.isValid("http://www.0.0.0.0.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Fail
	   try {
		   System.out.println("Testing - http://256.256.256.256.com");
		   assertTrue(urlVal.isValid("http://256.256.256.256.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://255.255.255.255.com");
		   assertTrue(urlVal.isValid("http://255.255.255.255.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Fail
	   try {
		   System.out.println("Testing - http://900.6.789.255.com");
		   assertTrue(urlVal.isValid("http://900.6.789.255.com"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   System.out.println("\n****************************");

   }
   
   public void testYourThirdPartition()
   {
	   
	   System.out.println("Port Test\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com:80");
		   assertTrue(urlVal.isValid("http://www.google.com:80"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com:3500");
		   assertTrue(urlVal.isValid("http://www.google.com:3500"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com:65535");
		   assertTrue(urlVal.isValid("http://www.google.com:65535"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: fail
	   try {
		   System.out.println("Testing - http://www.google.com:65636");
		   assertTrue(urlVal.isValid("http://www.google.com:65636"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	 //Expected Result: fail
	   try {
		   System.out.println("Testing - http://www.google.com:-1");
		   assertTrue(urlVal.isValid("http://www.google.com:-1"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }

	   System.out.println("\n****************************");
   }
   
   public void testYourFourthPartition()
   {
	   
	   System.out.println("Path Test\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com/test");
		   assertTrue(urlVal.isValid("http://www.google.com/test"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com/test/file");
		   assertTrue(urlVal.isValid("http://www.google.com/test/file"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com/test/");
		   assertTrue(urlVal.isValid("http://www.google.com/test/"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com/test//file");
		   assertTrue(urlVal.isValid("http://www.google.com/test//file"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: fail
	   try {
		   System.out.println("Testing - http://www.google.com/..");
		   assertTrue(urlVal.isValid("http://www.google.com/.."));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   System.out.println("\n****************************");
   }
   
   public void testYourFifthPartition()
   {
   
	   System.out.println("Query Test\n");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com?action=view");
		   assertTrue(urlVal.isValid("http://www.google.com?action=view"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Pass
	   try {
		   System.out.println("Testing - http://www.google.com?action=edit&mode=up");
		   assertTrue(urlVal.isValid("http://www.google.com?action=edit&mode=up"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Fail
	   try {
		   System.out.println("Testing - http://www.google.comaction=view");
		   assertTrue(urlVal.isValid("http://www.google.comaction=view"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   //Expected Result: Fail
	   try {
		   System.out.println("Testing - http://www.google.com????????????");
		   assertTrue(urlVal.isValid("http://www.google.com????????????"));
		   System.out.println("Passed");
	   } catch (Error err) {
		   System.out.println("Failed");
	   }
	   
	   System.out.println("\n****************************");

   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
