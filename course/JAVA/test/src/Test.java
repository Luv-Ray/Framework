public class Test {
	// ����һ����Ա���鱣����Ч�û�����Ϣ��
	String[] userDB = { "admin^123", "liu^456", "ascent^789" };

	// ����һ��login()�������û���½������Ч�Լ�飺
	public void login(String username, String password) {
		int i = 0;
		while (i < userDB.length) {
			byte[] b = userDB[i].getBytes();
			String u = "";
			String p = "";
			int j = 0;
			while (j < b.length) {
				if ('^' == b[j]) {
					u = userDB[i].substring(0, j);
					p = userDB[i].substring(j + 1, userDB[i].length());
					break;
				}
				j++;
			}
			if (u.equals(username) && p.equals(password)) {
				System.out.println("�û���¼�ɹ���");
				return;
			} else {
				if (i == userDB.length - 1) {
					System.out.println("�û������������");
				}
			}
			i++;
		}
	}

	// ����main()��������������������ΪҪ��¼���û���Ϣ�����в��ԣ�
	public static void main(String[] args) {

		String username = "admin_error";
		String password = "123";
		Test l = new Test();
		l.login(username, password);

	}

}
