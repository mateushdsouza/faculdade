package org.example.view;

import javax.swing.*;
import java.awt.*;

public class MenuPrincipal extends JFrame {
    public MenuPrincipal() {
        setSize(800,600);

        setLayout(new GridBagLayout());
        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(500, 300));
        panel.setBackground(Color.GRAY);

        add(panel);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        //Nome
        JLabel lblNome = new JLabel("Nome da Pessoa");
        lblNome.setBounds(10, 10, 120, 30);

        JTextField txtNome = new JTextField("Ex: Mateus Henrique");
        txtNome.setBounds(10, 40, 120, 30);



        //CPF
        JLabel lblCpf = new JLabel("CPF");
        lblCpf.setBounds(10, 70, 120, 30);

        JTextField txtCpf = new JTextField("Ex: 00000000000");
        txtCpf.setBounds(10, 100, 120, 30);



        JButton btnCadastrar = new JButton("Cadastrar");
        btnCadastrar.setBounds(10, 140, 100, 30);

        panel.add(lblNome);
        panel.add(txtNome);
        panel.add(lblCpf);
        panel.add(txtCpf);
        panel.add(btnCadastrar);

        panel.setLayout(null);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
