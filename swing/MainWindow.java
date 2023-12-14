
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MainWindow extends JFrame {
	
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private Client client;

    public MainWindow(Client client) {

        super("Télécommande");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.client = client;
        
        textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);
        
        
        JTextField messageCourt = new JTextField(20);
        JPanel panneauHautDroit = new JPanel(new BorderLayout());
        panneauHautDroit.add(messageCourt, BorderLayout.NORTH);
        add(panneauHautDroit, BorderLayout.LINE_END);

        
        JButton button1 = new JButton("Chercher fichier");
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //textArea.append("Bouton 1\n");
            	String response = client.send("findMultimedia "+messageCourt.getText()) + "\n";
    			textArea.append(response);
            }
        });

        JButton button2 = new JButton("Jouer fichier");
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //textArea.append("Bouton 2\n");
            	String response = client.send("play "+messageCourt.getText()) + "\n";
            	textArea.append(response);
            }
        });

        JButton button3 = new JButton("Quitter");
        button3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");

        JMenuItem menuItem1 = new JMenuItem("Chercher");
        menuItem1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //textArea.append("Bouton 1\n");
            	String response = client.send("findMultimedia "+messageCourt.getText()) + "\n";
    			textArea.append(response);
            }
        });
        menu.add(menuItem1);

        JMenuItem menuItem2 = new JMenuItem("Jouer");
        menuItem2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //textArea.append("Bouton 2\n");
            	String response = client.send("play "+messageCourt.getText()) + "\n";
    			textArea.append(response);
            }
        });
        menu.add(menuItem2);

        menuBar.add(menu);

        setJMenuBar(menuBar);

        
        JToolBar toolBar = new JToolBar();
        toolBar.add(button1);
        toolBar.add(button2);
        toolBar.add(button3);

        add(toolBar, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        pack();
        setVisible(true);
    }

}