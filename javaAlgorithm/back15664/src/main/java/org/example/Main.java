package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;

public class Main {
    private static int N,M;
    private static int[] arr, tmp;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        arr = new int[N];
        tmp = new int[N];
        for (int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        dfs(0, 0);
    }
    public static void dfs(int depth, int start){
        //종료 조건
        if(depth == M) {
            for (int i = 0; i < M; i++) {
                System.out.print(tmp[i] + " ");
            }
            System.out.println();
            return;
        }

        //조건
        for (int i = start; i < N; i++){
            tmp[depth] = arr[i];
            dfs(depth + 1, i + 1);
        }
    }
}
import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int arr[], result[];
    static StringBuilder sb = new StringBuilder();
    static boolean isVisited[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N+1];
        result = new int[M];
        isVisited = new boolean[N+1];

        st = new StringTokenizer(br.readLine(), " ");

        for(int i=1; i<=N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);
        DFS(1, 0);
        System.out.println(sb);
    }

    public static void DFS(int start, int depth) {
        int num = 0;

        if(depth == M) {
            for(int k : result)
                sb.append(k).append(' ');

            sb.append('\n');
            return;
        }

        for(int i=start; i<=N; i++) {
            if(!isVisited[i]) {
                if(num == arr[i])
                    continue;
            }

            isVisited[i] = true;
            result[depth] = arr[i];
            DFS(i+1, depth+1);
            isVisited[i] = false;
            num = arr[i];
        }
    }
}