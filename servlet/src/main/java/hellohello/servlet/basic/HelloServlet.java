package hellohello.servlet.basic;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet(name = "helloServlet", urlPatterns = "/hello")
public class HelloServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse respose) throws ServletException, IOException {
        System.out.println("HelloServlet.service");
        System.out.println("request = " + request);
        System.out.println("respose = " + respose);

        String username = request.getParameter("username");  //쿼리파라미터를 getParameter로 쉽게 조회할수있다
        System.out.println("username = " + username);

        respose.setContentType("text/plain");
        respose.setCharacterEncoding("utf-8");                //여기까지는 content타입에 들어간다. 헤더정보로 들어간다
        respose.getWriter().write("hello " + username);        //http data body에 값이 들어간다
    }
}
