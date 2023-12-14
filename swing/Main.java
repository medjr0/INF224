
public class Main
{
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	static final int WIDTH = 800;
	static final int HEIGHT = 400;

	public static void main(String argv[])
	{
		String host = DEFAULT_HOST;
	    int port = DEFAULT_PORT;
	    if (argv.length >=1) host = argv[0];
	    if (argv.length >=2) port = Integer.parseInt(argv[1]);
	    
	    Client client = null;
	    
	    try {
	      client = new Client(host, port);
	    }
	    catch (Exception e) {
	      System.err.println("Client: Couldn't connect to "+host+":"+port);
	      System.exit(1);
	    }
	    
	    System.out.println("Client connected to "+host+":"+port);
	    
		new MainWindow(client);
}
}