/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;


public class UrlValidatorTest extends TestCase {




   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest() {

       /*
                <SCHEME> <AUTHORITY> <PORT> <PATH> <QUERY>
        */

       System.out.println("");
       System.out.println("******** MANUAL TESTS ********");

       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       //TEST ONE
        /* <SCHEME: true> <AUTHORITY: true> <PORT: true>  */
       System.out.print("Test 1, Expect True, Result:  ");
       System.out.print(urlVal.isValid("http://www.amazon.com/"));
       if (!urlVal.isValid("http://www.amazon.com/"))
       {
           System.out.println("  <POTENTIAL BUG>");

       }
       else System.out.println("");

       //TEST TWO
        /* <SCHEME: true> <AUTHORITY: true> <PORT: true> <PATH: true> */
       System.out.print("Test 2, Expect True, Result:  ");
       System.out.print(urlVal.isValid("https://www.amazon.com/ref=nav_logo"));
       if (!urlVal.isValid("https://www.amazon.com/ref=nav_logo"))
       {
           System.out.println("  <POTENTIAL BUG>");

       }
       else System.out.println("");

       //TEST THREE
        /* <SCHEME: true> <AUTHORITY: true> <PORT: true> <PATH: true> <QUERY: true>*/
       System.out.print("Test 3, Expect True, Result:  ");
       System.out.print(urlVal.isValid("https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Dog"));
       if (!urlVal.isValid("https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Dog"))
       {
           System.out.println("  <POTENTIAL BUG>");

       }
       else System.out.println("");

       //TEST FOUR
        /* <SCHEME: true> <AUTHORITY: false> <PORT: true> <PATH: true> <QUERY: true>*/
       System.out.print("Test 4, Expect False, Result:  ");
       System.out.print(urlVal.isValid("https://www.am azon.com/ref=nav_logo"));
       if (urlVal.isValid("https://www.am azon.com/ref=nav_logo"))
       {
           System.out.println("  <POTENTIAL BUG>");

       }
       else System.out.println("");

       //TEST FIVE
        /* <SCHEME: false> <AUTHORITY: true> <PORT: true> <PATH: true> <QUERY: true>*/
       System.out.print("Test 5, Expect False, Result:  ");
       System.out.print(urlVal.isValid("hxxps://www.amazon.com/ref=nav_logo"));
       if (urlVal.isValid("hxxps://www.amazon.com/ref=nav_logo"))
       {
           System.out.println("  <POTENTIAL BUG>");

       }
       else System.out.println("");
       System.out.println("");


   }

    public void testSchemePartition() {

        /*
                <SCHEME> <AUTHORITY> <PORT> <PATH> <QUERY>
        */

        System.out.println("");
        System.out.println("******** SCHEME PARTITION TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        System.out.print("TEST VALID SCHEMES : ");
        if (urlVal.isValid("http://www.amazon.com")
                &&
                urlVal.isValid("ftp://www.amazon.com")
                &&
                urlVal.isValid("https://www.amazon.com"))
        {
            System.out.println("valid input schemes passed as expected");
        }
        else
        {
            System.out.println("valid input schemes failed indication of a possible bug");
        }

        System.out.print("TEST INVALID SCHEMES : ");
        if (!urlVal.isValid("//www.amazon.com")
                &&
                !urlVal.isValid("http:www.amazon.com")
                &&
                !urlVal.isValid("http:/www.amazon.com")
                &&
                !urlVal.isValid("htttp/www.amazon.com")
                &&
                !urlVal.isValid("hxxp://www.amazon.com")
                &&
                !urlVal.isValid("7ht://www.amazon.com"))
        {
            System.out.println("schemes failed as expected");
        } else
        {
            System.out.println("invalid input scheme passed,   <POTENTIAL BUG> ");
        }

        System.out.println("");
    }
   
   //Resource for finding boundary cases
   //http://formvalidation.io/validators/ip/
   public void testAuthorityPartition()
   {
        /*
                <SCHEME> <AUTHORITY> <PORT> <PATH> <QUERY>
        */

       System.out.println("");
       System.out.println("******** AUTHORITY PARTITION TESTS ********");

       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       System.out.print("TEST VALID AUTHORITY: ");
       if (urlVal.isValid("http://www.amazon.com")
               &&
               !urlVal.isValid("http://256.255.255.255")
               &&
               urlVal.isValid("http://255.255.255.255")
               &&
               !urlVal.isValid("192.168 224.0"))
       {
           System.out.println(" passed as expected");
       }
       else
       {
           System.out.println("valid authority passed,   <POTENTIAL BUG> ");
       }

       System.out.print("TEST INVALID AUTHORITY: ");
       if (!urlVal.isValid("http://fake.xyz")
               &&
               !urlVal.isValid("http://.xyz")
               &&
               !urlVal.isValid("http://fake.tcp.xyz")
               &&
               urlVal.isValid("http://0.0.0.0")
               &&
               urlVal.isValid("192.168.1.1"))
       {
           System.out.println("failed as expected");
       }
       else
       {
           System.out.println("invalid authority failed,   <POTENTIAL BUG> ");
       }


   }
   
   public void testPortPartition(){

        /*
                <SCHEME> <AUTHORITY> <PORT> <PATH> <QUERY>
        */

       System.out.println("");
       System.out.println("******** PORT PARTITION TESTS ********");

       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       System.out.print("TEST VALID PORT : ");
       if (urlVal.isValid("http://www.amazon.com:0")
               &&
               urlVal.isValid("http://www.amazon.com:88")
               &&
               urlVal.isValid("http://www.amazon.com:80")
               &&
               urlVal.isValid("http://www.amazon.com:45566")
               &&
               urlVal.isValid("http://www.amazon.com:12345"))
       {
           System.out.println("passed as expected");
       }
       else
       {
           System.out.println("valid port failed,   <POTENTIAL BUG> ");
       }

       System.out.print("TEST INVALID PORT : ");
       if (!urlVal.isValid("http://www.amazon.com:-1")
               &&
               !urlVal.isValid("http://www.amazon.com:a50")
               &&
               !urlVal.isValid("http://www.amazon.com:50a")
               &&
               urlVal.isValid("http://www.amazon.com:100000000"))
       {
           System.out.println("failed as expected");
       }
       else
       {
           System.out.println("invalid port passed,   <POTENTIAL BUG> ");
       }

       System.out.println("");
   }
    
   
    public void testPathPartition() {

        /*
                <SCHEME> <AUTHORITY> <PORT> <PATH> <QUERY>
        */

        System.out.println("");
        System.out.println("******** PATH PARTITION TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        System.out.print("TEST VALID PATH : ");
        if (urlVal.isValid("http://www.amazon.com/ref=nav_logo")
                &&
                urlVal.isValid("http://www.amazon.com/Cyber-Monday/b")
                &&
                urlVal.isValid("http://www.amazon.com/")
                &&
                urlVal.isValid("http://www.amazon.com//")
                &&
                urlVal.isValid("http://www.amazon.com/."))
        {
            System.out.println("passed as expected");
        }
        else
        {
            System.out.println("valid path failed,   <POTENTIAL BUG> ");
        }

        System.out.print("TEST INVALID PATH : ");
        if (!urlVal.isValid("http://www.amazon.com/....")
                &&
                !urlVal.isValid("http://www.amazon.com/ .")
                &&
                !urlVal.isValid("http://www.amazon.com/..")
                &&
                !urlVal.isValid("http://www.amazon.com/../")
                &&
                !urlVal.isValid("http://www.amazon.com/!"))
        {
            System.out.println("failed as expected");
        }
        else
        {
            System.out.println("invalid path passed,   <POTENTIAL BUG> ");
        }

        System.out.println("");

    }

    /**
     * Create set of tests by taking the testUrlXXX arrays and running through
     * all possible permutations of their combinations.
     *
     * @param //testObjects
     *            Used to create a url.
     */

    public void testIsValidScheme() {

        System.out.println("");
        System.out.println("********  SCHEME TESTS ********");
        
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String url;
        Boolean valid;

        for (ResultPair testPair : authorities) {
            url = testPair.item;
            valid = urlVal.isValid(url);

            if ((testPair.valid && valid) || (!testPair.valid && !valid))
            {
                System.out.println("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid);

            }
            else
            {
                System.out.print("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid +" ");
                System.out.println("  <POTENTIAL BUG>");
            }
        }


        System.out.println("");

    }

    public void testIsValidAuthority() {

        System.out.println("");
        System.out.println("********  AUTHORITY TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String url;
        Boolean valid;

        for (ResultPair testPair : schemes) {
            url = testPair.item;
            valid = urlVal.isValid(url);

            if ((testPair.valid && valid) || (!testPair.valid && !valid))
            {
                System.out.println("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid);
            }
            else
            {
                System.out.print("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid +" ");
                System.out.println("  <POTENTIAL BUG>");
            }
        }


        System.out.println("");

    }


    public void testIsValidPort() {


        System.out.println("");
        System.out.println("********  PORT TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String base = "http://www.amazon.com";
        String url;
        Boolean valid;

        for (ResultPair testPair : ports) {
            url = base + testPair.item;
            valid = urlVal.isValid(url);

            if ((testPair.valid && valid) || (!testPair.valid && !valid))
            {
                System.out.println("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid);            }
            else
            {
                System.out.print("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid +" ");
                System.out.println("  <POTENTIAL BUG>");
            }
        }

        System.out.println("");

    }


    public void testIsValidPath() {

        System.out.println("");
        System.out.println("********  PATH TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String base = "http://www.amazon.com:80";
        String url;
        Boolean valid;

        for (ResultPair testPair : paths) {
            url = base + testPair.item;
            valid = urlVal.isValid(url);

            if ((testPair.valid && valid) || (!testPair.valid && !valid))
            {
                System.out.println("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid);            }
            else
            {
                System.out.print("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid +" ");
                System.out.println("  <POTENTIAL BUG>");
            }
        }

        System.out.println("");
    }


    public void testIsValidQuery() {

        System.out.println("");
        System.out.println("********  QUERY TESTS ********");

        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String base = "http://www.amazon.com:80/path";
        String url;
        Boolean valid;

        for (ResultPair testPair : queries) {
            url = base + testPair.item;
            valid = urlVal.isValid(url);

            if ((testPair.valid && valid) || (!testPair.valid && !valid))
            {
                System.out.println("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid);            }
            else
            {
                System.out.print("Test " +testPair+ ":" + url + " Expect: " + testPair.valid + " -> Result: " + valid +" ");
                System.out.println("  <POTENTIAL BUG>");
            }
        }

        System.out.println("");

    }

    ResultPair[] schemes = {
            new ResultPair("/", false),
            new ResultPair("://", false),
            new ResultPair(":", false),
            new ResultPair("https://", true),
            new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("numbers", false),
            new ResultPair("1234", false),
            new ResultPair("!!", false),
            new ResultPair("http:", false),
            new ResultPair("word://", true),
            new ResultPair("word", false)};

    ResultPair[] authorities = {
            new ResultPair("www.ama zon.com", false),
            new ResultPair("123", false),
            new ResultPair("www.amazon.com", true),
            new ResultPair("amazon.com", true),
            new ResultPair("192.168.1.1", true),
            new ResultPair("0.0.0.0", true),
            new ResultPair("1000.1000.1000.1000", false),
            new ResultPair("1.1.1.256", false),
            new ResultPair("192.168.224.0", false),
            new ResultPair("192.168.224.0 1", false),
            new ResultPair("2001:0000:1234:0000:0000:C1C0:ABCD:0876", false),
            new ResultPair("2001:0000:1234:0000:0000:C1C0:ABCD:0876 0", false),
            new ResultPair("....", false),
            new ResultPair("abcd", false),
            new ResultPair(".a.b.c.d", false) };

    ResultPair[] ports = {
            new ResultPair("", true),
            new ResultPair(":80", true),
            new ResultPair(":143", true),
            new ResultPair(":1023", false),
            new ResultPair(":5a", false),
            new ResultPair(":a5", false),
            new ResultPair(":5a5", false),
            new ResultPair(":5555a", false),
            new ResultPair(":!", false),
            new ResultPair(":65535", true),
            new ResultPair(":65536", false),
            new ResultPair(":10000000", false),
            new ResultPair(":-0", false),};

    ResultPair[] paths = {
            new ResultPair("//", true),
            new ResultPair("/", true),
            new ResultPair("/path", true),
            new ResultPair("/.", true),
            new ResultPair("/..", false),
            new ResultPair("/!", true),
            new ResultPair("/path/too", true),
            new ResultPair("//path", true),
            new ResultPair("/./path", true),
            new ResultPair("/paaaaaaaaaaath", true),
            new ResultPair("/2012", true)};

    ResultPair[] queries = {
            new ResultPair("!key==value", false),
            new ResultPair("!key=value", false),
            new ResultPair("?key=value", true),
            new ResultPair("?source=twitter&content=socialwelcome", true),
            new ResultPair("?source=twitter&content=socialwelcome?source=twitter&content=socialwelcome", true),
            new ResultPair("&key=value", false),
            new ResultPair("?key==value", true),
            new ResultPair("?key=?value", true),
            new ResultPair("?key=??value", true) };


}
